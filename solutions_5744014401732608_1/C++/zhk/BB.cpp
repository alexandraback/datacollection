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

typedef long long i64;

int mask[64][64];

void work(int N, i64 M) {
    F0(i, N+2) F0(j, N+2) mask[i][j] = 0;
    for (int i=2; i<N; ++i) {
        for(int j=i+1; j<=N; ++j)
            mask[i][j] = 1;
    }
    mask[1][N] = 1;
    M--;
    for (int i=0; (1LL<<i) <= M; ++i) {
        if ((M>>i) & 1) {
            int j = N - (i+1);
            if (j < 2) throw std::runtime_error("invalid");
            mask[1][j] = 1;
        }
    }
    F1(i, N) {
        F1(j, N) printf("%d", mask[i][j]);
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int T;cin >> T;
    F1(Ti, T) {
        i64 B, M;
        cin >> B >> M;
        printf("Case #%d: ", Ti);
        if (M > (1<<(B-2))) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("POSSIBLE\n");
            work(B, M);
        }
    }
    return 0;
}
