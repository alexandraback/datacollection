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

inline int R() {int v; scanf("%d", &v); return v;}


const int NN = 1000000 + 8;

int  F[NN] = {0, 1, 2, 3, 4};

int calc() {
    
}

int rev(int v) {
    int r = 0;
    for(; v; v/=10) {
        r = r*10 + (v%10);
    }
    return r;
}

int main(int argc, char *argv[]) {
    for(int i=3; i<NN; ++i) {
        F[i] = F[i-1] + 1;
        int j = rev(i);
        if (j < i && rev(j)==i) cMin(F[i], F[j] + 1);
        // if (F[i] < F[i-1]) putchar('\n');
        // if (i < 10000) printf("%d ", F[i]);
    }
    // puts("");
    // return 0;
    int T = R();
    F1(iT, T) {
        int n = R();
        printf("Case #%d: %d\n", iT, F[n]);
    }
    return 0;
}
