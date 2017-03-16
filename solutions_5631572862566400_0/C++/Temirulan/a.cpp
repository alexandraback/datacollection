#pragma comment(linker, "/STACK:64000000")
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, a[100100];
int used[100100];
vector <int> g[100100];
int two_cycled = 0;
map <pii, int> cycle;
int cycle_size[100100];
int dp[100100];

void add(int x, int y) {
    cycle[mp(x, y)] = 1;
}

bool is_cycle(int x, int y) {
    return cycle[mp(x, y)]||cycle[mp(y,x)];
}

void dfs(int v, int cc) {
    if (used[v] == cc) return;
    used[v] = cc;
    forit (it, g[v]) {
        int to = *it;
        dfs(to, cc);
    }
}

int calc(int v, int par) {
    int &res = dp[v];
    if (res != -1) return res;
    res = 1;
    forit (it, g[v]) {
        int to = *it;
        if (!is_cycle(v, to) && to != par) {
            res = max(res, 1 + calc(to, v));
        }
    }
    return res;
}

void solve(int case_num) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        dp[i] = -1;
        a[i]--;
    }
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n; i++) {
        int x = a[i];
        g[x].pb(i);
        g[i].pb(x);
    }
    two_cycled = 0;
    for (int i = 0; i < n; i++) used[i] = 0;
    cycle.clear();
    vector <int> has(n, -1);
    int cc = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            dfs(i, cc);
            int x = i;
            int cur = 0;
            int sz = -1;
            while(true) {
                if (has[a[x]] != -1) {
                    sz = cur - has[a[x]] + 1;
                    break;
                }
                has[x] = cur;
                x = a[x];
                cur++;
            }
            assert(sz != -1);
            int st = x;
            while (a[x] != st) {
                add(x, a[x]);
                add(a[x], x);
                x = a[x];
            }
            cycle_size[cc] = sz;
            ans = max(ans, sz);
            if (sz == 2) {
                int chain = calc(x, -1) + calc(a[x], -1);
                ans = max(ans, chain);
                two_cycled += chain;
            }
            cc++;
        }
    }
    ans = max(ans, two_cycled);
    printf("Case #%d: %d\n", case_num, ans);
}


int main(){

    int T;

    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
        solve(i);

    return 0;
}
