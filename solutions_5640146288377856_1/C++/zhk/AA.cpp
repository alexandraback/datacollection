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


int nF[32][32];
int yF[32][32];

int nCalc(int C, int W) {
    if (W == 1) return C;
    if (C < W) return 0;
    if (W*2 > C) return 1;
    if (nF[C][W] >= 0) return nF[C][W];
    return nF[C][W] = nCalc(C-W, W) + 1;
}

int yCalc(int C, int W) {
    if (W == 1) return C;
    if (C < W) return C;
    if (C == W) return W;
    if (W*2 > C) return W + 1;
    int& ans = yF[C][W];
    return ans >= 0 ? ans : (ans = yCalc(C-W, W) + 1);
}


int main(int argc, char *argv[]) {
    memset(nF, 0xff, sizeof(nF));
    memset(yF, 0xff, sizeof(yF));
    int T;
    cin >> T;
    F1(iT, T) {
        int R, C, W;
        cin >> R >> C >> W;
        printf("Case #%d: %d\n", iT, nCalc(C, W) * (R - 1) + yCalc(C, W));
    }
    return 0;
}
