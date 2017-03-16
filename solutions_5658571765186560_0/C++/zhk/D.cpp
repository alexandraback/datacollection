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

inline int R(){int v;scanf("%d", &v);return v;}

bool calc(int X, int R, int C) {
    if(R*C < X || std::max(R,C) < X || (R*C)%X) return false;
    if (X <= 2) return true;
    if (X == 3) return std::min(R,C) >= 2;
    if (X == 4) return std::min(R,C) >= 3;
    if (X == 5) return std::min(R,C) >= 4;
    if (X == 6) return std::min(R,C) >= 5;
    return false;
}

int main(int argc, char *argv[]) {
    int T = R();
    F1(iT, T) {
        int X, R, C;
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: %s\n", iT, calc(X, R, C) ? "GABRIEL": "RICHARD");
    }
    return 0;
}
