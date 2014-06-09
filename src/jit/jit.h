struct MVMJitGraph {
    MVMSpeshGraph * spesh;
    MVMSpeshIns * entry;
    MVMSpeshIns * exit;
};

typedef enum {
    MVM_JIT_ARG_STACK, // relative to stack base
    MVM_JIT_ARG_MOAR, // relative to register base
    MVM_JIT_ARG_CONST, // constant number
} MVMJitArgBase;

struct MVMJitCallArg {
    MVMJitArgBase base;
    MVMuint64 offset;
};

struct MVMJitCallC {
    void * func_ptr; // what do we call
    MVMJitCallArg * args;
    MVMuint16 num_args; // how many arguments we pass
    MVMuint16 has_vargs; // does the receiver consider them variable
};



typedef void (*MVMJitCode)(MVMThreadContext *tc, MVMFrame *frame);

MVMJitGraph* MVM_jit_try_make_jit_graph(MVMThreadContext *tc, MVMSpeshGraph *spesh);
MVMJitCode MVM_jit_compile_graph(MVMThreadContext *tc, MVMJitGraph *graph);

