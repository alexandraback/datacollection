#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << (x) << endl
#define dbg2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define dbg3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl

template<class T> inline T cabs(T x) { return x > 0 ? x : (-x); }
template<class T> inline T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }

#define out(x) cout << (x) << endl
#define out2(x,y) cout << (x) << " " << (y) << endl
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl

int n; vector<int> adj;

int go(int up, int dn)
{
    return max(0, (up - 1) / dn);
}

int run(int low)
{
    int res = 0;
    for(int i = 0; i < n; i ++)
        res += go(adj[i], low);
    return res;
}

int gao()
{
    int mx = 0;
    for(int i = 0; i < n; i ++)
        mx = max(adj[i], mx);
    int res = mx;
    for(int low = 2; low < mx; low ++)
        res = min(res, low + run(low));
    return res;
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int idx = 0, nt;
    scanf("%d", &nt);
    for(; nt > 0; nt --) {
        scanf("%d", &n); adj.clear();
        for(int i = 0, j; i < n; i ++) {
            scanf("%d", &j);
            adj.push_back(j);
        }
        printf("Case #%d: %d\n", ++idx, gao());
    }
    return 0;
}
