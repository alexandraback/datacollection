#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define inf (1<<30)
const int N = (1<<20)-1;
const int M = 145;
unsigned int vis[1<<20];
int reverse(int x)
{
    int v = 0;
    while (x > 0) {
        v = v * 10 + x % 10;
        x /= 10;
    }
    return v;
}
int gao(int n)
{
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int v = vis[x];
        if (x == n)
            return vis[x];
        if (!vis[x+1]) {
            q.push(x+1);
            vis[x+1] = v + 1;
        }
        int t = reverse(x);
        if (t <= n && !vis[t]) {
            q.push(t);
            vis[t] = v + 1;
        }
    }
    return -1;
}
int main()
{
    freopen("/Users/junchen/topcoder/tc/tc/A-small-attempt0.in", "r", stdin);
    freopen("/Users/junchen/topcoder/tc/tc/a.out", "w", stdout);
    int T, n;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        cin >> n;
        printf("Case #%d: %d\n", ca, gao(n));
    }
}