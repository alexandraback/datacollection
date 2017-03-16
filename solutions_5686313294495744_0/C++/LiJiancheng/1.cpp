#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define N 1005
map<string, int> m1, m2;
int n, s1, s2;
struct graph
{
    vector<int> g[N];
    bool S[N], T[N];
    int l[N];
    int n, m;
    void init(int _n, int _m)
    {
        n = _n, m = _m;
        for (int i = 0; i < n; ++i)
            g[i].clear();
    }
    void add(int i, int j)
    {
        g[i].push_back(j);
    }
    bool find(int k)
    {
        S[k] = 1;
        for (int i = 0; i < g[k].size(); ++i)
        {
            int j = g[k][i];
            if (!T[j])
            {
                T[j] = 1;
                if (l[j] < 0 || find(l[j]))
                {
                    l[j] = k;
                    return 1;
                }
            }
        }
        return 0;
    }
    int max_match()
    {
        int ans = 0;
        for (int i = 0; i < m; ++i)
            l[i] = -1;
        for (int i = 0; i < n; ++i)
        {
            memset(T, 0, sizeof(T));
            if (find(i)) ++ans;
        }
        return ans;
    }
} g;

void solve()
{
    cin >> n;
    m1.clear();
    m2.clear();
    s1 = s2 = 0;
    g.init(n, n);
    for (int i = 0; i < n; ++i)
    {
        string w1, w2;
        cin >> w1 >> w2;
        if (!m1[w1])
            m1[w1] = ++s1;
        if (!m2[w2])
            m2[w2] = ++s2;
        g.add(m1[w1] - 1, m2[w2] - 1);
        printf("%d %d\n", m1[w1], m2[w2]);
    }
    g.n = s1;
    g.m = s2;
    int ans = g.max_match();
    printf("%d\n", n - (s1 + s2 - ans));
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    // freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}