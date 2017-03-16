#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdio>

using namespace std;

vector<vector<int> > g;

int was[2001] = {0};
int num[2001] = {0};
int kol = 0;

void srt(int v)
{
    if (was[v] == 1) return;
    was[v] = 1;
    for (int i = 0; i < g[v].size(); ++i)
        srt(g[v][i]);
    num[v] = kol++;
}

bool dfs(int v)
{
    if (was[v] == 1) return false;
    was[v] = 1;
    for (int i = 0; i< g[v].size(); ++i)
    {
        int to = g[v][i];
        if (was[to] == 1) return true;
        if (dfs(to)) return true;
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        g.clear();
        g.resize(N + 1);
        memset(was, 0, sizeof(was));
        memset(num, 0, sizeof(num));
        kol = 0;
        for (int i = 1; i <= N; ++i)
        {
            int M;
            cin >> M;
            g[i].clear();
            g[i].resize(M);
            for (int j = 0; j < M; ++j) cin >> g[i][j];
        }
        for (int i = 1; i <= N; ++i) srt(i);
        int l[2001] = {0};
        for (int i = 1; i <= N; ++i) l[num[i]] = i;
        bool flag = false;
        for (int i = N - 1; i >= 0; --i)
        {
            memset(was, 0, sizeof(was));
            set<int> d;
            if (dfs(l[i]))
            {
                flag = true;
                break;
            } 
        }       
        cout << "Case #" << t << ": ";
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}