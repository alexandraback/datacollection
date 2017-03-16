#include <bits/stdc++.h>
using namespace std;
#define GET4(_1,_2,_3,_4,...) _4
#define rep_(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) GET4(__VA_ARGS__,repi,rep_,)(__VA_ARGS__)
#define all(c) begin(c),end(c)

const int N = 1024;
int n, f[N];

void input()
{
    cin >> n;
    rep(i, n) cin >> f[i], --f[i];
}

bool used[N];
int d[N];

int dfs(int i)
{
    if (used[f[i]]) return -1;
    if (d[f[i]] != -1) {
        return d[i] - d[f[i]] + 1;
    } else {
        d[f[i]] = d[i] + 1;
        return dfs(f[i]);
    }
}

void block(int i)
{
    used[i] = true;
    if (not used[f[i]]) block(f[i]);
}

int max_cycle()
{
    fill_n(used, n, false);
    fill_n(d, n, -1);
    int ret = 0;
    rep(i, n) if (d[i] == -1) {
        d[i] = 0;
        ret = max(ret, dfs(i));
        block(i);
    }
    return ret;
}

vector<vector<int> > G;
bool paired[N];
int h[N];

int dfs1(int i)
{
    int& ret = h[i];
    for (int j: G[i]) if (not paired[j]) {
        ret = max(ret, dfs1(j) + 1);
    }
    return ret;
}

void solve()
{
    G.assign(n, vector<int>());
    fill_n(paired, n, false);
    fill_n(h, n, 0);

    rep(i, n) G[f[i]].push_back(i);
    int ans = 0;
    rep(i, n) if (not paired[i] and f[f[i]] == i) {
        paired[i] = paired[f[i]] = true;
        ans += dfs1(i) + dfs1(f[i]) + 2;
    }
    ans = max(ans, max_cycle());
    cout << ans << endl;
}

int main()
{
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
}
