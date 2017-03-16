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

int N, A[1024];

int calc2(int m) {
    int  ans = 0;
    F0(i, N) {
        if (A[i] > m) {
            int c = A[i] / m;
            if (c*m < A[i]) ++c;
            ans += c - 1;
        }
    }
    return ans;
}

int calc() {
    int D = R();
    N = D;
    std::priority_queue<int> Q;
    F0(i, D) A[i] = R();
    int  ans = *max_element(A, A+D);
    for(int i=1; i<ans; ++i) cMin(ans, i + calc2(i));
    return ans;
}

int main(int argc, char *argv[]) {
    int T = R();
    F1(iT, T) {
        printf("Case #%d: %d\n", iT, calc());
    }
    return 0;
}
