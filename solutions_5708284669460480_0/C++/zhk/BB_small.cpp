#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)

int  K, L, S;
char Ks[32], Ls[32], Ts[32];
int max_cnt = 0;
long long tot_cnt = 0;

inline bool is_suffix(int n) {
    char* src = Ts + n - L;
    char* dst = Ls;
#define ZZZ(z) case z: return memcmp(src, dst, z) == 0
    switch(L) {
        case 1: return *src == *dst;
            ZZZ(2); ZZZ(3); ZZZ(4); ZZZ(5); ZZZ(6); ZZZ(7);
        default: memcpy(src, dst, L) == 0;
    }
    return true;
}

inline int do_it(int mask) {
    int cc = 0;
    F0(i, S) {
        int Ki = mask % K;
        mask /= K;
        Ts[i] = Ks[Ki];
        if (i+1 >= L && is_suffix(i+1)) {
            ++cc;
        }
    }
    return cc;
}

double calc() {
    int mask_end = 1;
    F0(i, S) mask_end *= K;
    max_cnt = 0;
    tot_cnt = 0;
    F0(mask, mask_end) {
        int cc = do_it(mask);
        cMax(max_cnt, cc);
        tot_cnt += cc;
    }
    return max_cnt - ((double)tot_cnt*1.0 / (double)mask_end);
}

int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    F1(iT, T) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s%s", Ks, Ls);
        printf("Case #%d: %.9f\n", iT, calc());
    }
    return 0;
}
