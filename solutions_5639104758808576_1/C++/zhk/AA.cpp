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

char S[1024];

int main(int argc, char *argv[]) {
    int T; scanf("%d", &T);
    F1(iT, T) {
        int N;
        scanf("%d%s", &N, S);
        int ans = 0;
        int sum = S[0] - '0';
        F1(i, N) {
            int cur = S[i] - '0';
            if (cur < 0 || cur > 9) cur = 0;
            if (cur == 0) continue;
            if (sum + ans < i) {
                ans += i - sum - ans;
            }
            sum += cur;
        }
        printf("Case #%d: %d\n", iT, ans);
    }
    return 0;
}
