#include "../template/codejam-dsl.hpp"

int N, M, A[100], B[100];
lng a[100], b[100];

inline bool adv(int& ia, lng& ca, int& ib, lng& cb) {
    if (ca == a[ia]) { ca = 0; ++ia; }
    if (cb == b[ib]) { cb = 0; ++ib; }
    return (ia == N || ib == M);
}

lng ser(lng R, int ia, lng ca, int ib, lng cb, int lev = 0) {
    if (db) {
        fprintf(stderr, "%*s", lev, "");
        P1l(R); P1(ia); P1l(ca); P1(ib); P1(cb); PNL();
        fprintf(stderr, "%*s", lev+2, "");
        FO(i,ia,N) fprintf(stderr, "%lld-%d ", a[i], A[i]); PNL();
        fprintf(stderr, "%*s", lev+2, "");
        FO(i,ib,M) fprintf(stderr, "%lld-%d ", b[i], B[i]); PNL();
    }

    if (ia == N || ib == M) return R;
    if (adv(ia,ca,ib,cb)) return R;

    while (A[ia] == B[ib]) {
        lng cc = min(a[ia] - ca, b[ib] - cb);
        R += cc; ca += cc; cb += cc;
        if (adv(ia,ca,ib,cb)) return R;
    }
    
    lng RL = 0;
    FO(sia, ia+1, N) if (A[sia] == B[ib]) {
        RL = max(RL, ser(R, sia, 0, ib, cb, lev+1));
        break;
    }
    
    lng RR = 0;
    FO(sib, ib+1, M) if (A[ia] == B[sib]) {
        RR = max(RR, ser(R, ia, ca, sib, 0, lev+1));
        break;
    }
    return max(R, max(RL, RR));
}

void run() {
    N = rdi(); M = rdi();
    FZ(i,N) { a[i] = rdl(); A[i] = rdi(); }
    FZ(i,M) { b[i] = rdl(); B[i] = rdi(); }
    printf("%lld", ser(0, 0, 0, 0, 0));
}
