#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int N = 100010;
int n, s[N], f[N], sz;
string z, t;
map<string, int> ma, mb;
vector<int> v[N];
vector<pair<int, int>> u;
queue<int> q;

void add_edge(int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

void dfs(int c)
{
    f[c] = true; sz++;
    for (auto i : v[c]) if (!f[i]) dfs(i);
}

void solve(int test)
{
    int x = 0, y = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> z >> t;
        if (!ma[z]) ma[z] = ++x;
        if (!mb[t]) mb[t] = ++y;
        u.push_back({ma[z], mb[t]});
    }
    int m = x + y;
    for (auto i : u) add_edge(i.first, x + i.second);
    for (int i = 1; i <= m; i++)
    {
        s[i] = v[i].size();
        if (s[i] == 1) q.push(i);
    }
    int sol = 0;
    while (!q.empty())
    {
        int c = q.front(), r = 0; q.pop();
        if (f[c]) continue;
        for (auto i : v[c]) if (!f[i]) r = i;
        if (!r) continue;
        sol++;
        f[c] = f[r] = true;
        for (auto i : v[r]) if (!f[i])
        {
            s[i]--;
            if (s[i] == 1) q.push(i);
        }
    }
    for (int i = 1; i <= m; i++) if (!f[i])
    {
        sz = 0;
        dfs(i);
        sol += (sz + 1) / 2;
    }
    cout << "Case #" << test << ": " << n - sol << endl;
    for (int i = 1; i <= m; i++) s[i] = f[i] = 0, v[i].clear();
    ma.clear(); mb.clear();
    u.clear();
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
