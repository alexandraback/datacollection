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

int _MUL[4][4] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};
int MUL[8][8];
int MAP[256];

inline int Mul(int a, int b) {return MUL[a][b];}


typedef long long i64;
int  L;
i64  X;
char S[1<<22];

int Exp(int a, i64 b) {
    int c = 0;
    for(; b>0; b>>=1) {
        if (b&1) c = Mul(c, a);
        a = Mul(a, a);
    } return c;
}

int calc_pos(int z, int v) {
    int idx = 0;
    int cur = 0;
    F0(zi, z) {
        F0(i, L) {
            cur = Mul(cur, S[i]);
            if (cur == v) return idx;
            ++idx;
        }
    }
    return -1;
}

int calc_pos2(int z, int v) {
    int idx = z*L-1;
    int cur = 0;
    F0(zi, z) {
        F0(i, L) {
            cur = Mul(S[L-i-1], cur);
            if (cur == v) return idx;
            --idx;
        }
    }
    return -1;
}


bool calc() {
    scanf("%d%lld%s", &L, &X, S);
    int  ALL = 0;
    F0(i, L) ALL = Mul(ALL, MAP[S[i]]);
    if (Exp(ALL,X) != 4) return false;
    // puts("\npass one");
    i64 t = 4*3 + (X & 4);
    if (t > X) t = X;
    F0(i, L) S[i] = MAP[S[i]];
    int  ip = calc_pos((int)t, 1);
    if (ip < 0) return false;
    int  kp = calc_pos2((int)t, 3);
    if (kp < 0) return false;
    // printf("\nip[%d] kp[%d] Z[%d]\n", ip, kp, (int)(L*t));
    if (ip < kp) return true;
    return false;
}

int main(int argc, char *argv[]) {
    MAP['i'] = 1;
    MAP['j'] = 2;
    MAP['k'] = 3;
    F0(a, 8) F0(b, 8) MUL[a][b] = _MUL[a&3][b&3]^((a&4)^(b&4));
    int T;scanf("%d", &T);
    F1(iT, T) {
        printf("Case #%d: %s\n", iT, calc() ? "YES" : "NO");
    }
    return 0;
}
