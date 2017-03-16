#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

int dp[1000020];

int go(int u) {
    int &res = dp[u];
    if (res != -1) return res;

    res = go(u-1) + 1;
    
    if (u % 10 != 0) {
        int U = u;
        int v = 0;
        while (U) {
            v *= 10;
            int d = U % 10;
            v += d;
            U /= 10;
        }
//        dbg2(u, v);
        if (v < u) res = min(res, go(v) + 1);
    }
    return res;
}

int main() { 

    int T;
    cin >> T;
    CLR(dp, -1);

    dp[1] = 1;
    REPN(i, 2, 1000010) {
        go(i);
    }

    REP(tc, T) {
        int n;
        cin >> n;
        cout << "Case #" << tc+1 << ": " << dp[n] <<"\n";
    }

	return 0;
}
