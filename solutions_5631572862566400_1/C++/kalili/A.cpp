#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<iomanip>
#include<climits>
#include<fstream>
using namespace std;



const int MAXN = 1001;

int visited[MAXN], f[MAXN], maxCycleLen, n;

void dfs(int now, int start, int depth)
{
    visited[now] = depth;
    if (visited[f[now]] == -1)
        dfs(f[now], start, depth + 1);
    else
    {
        if (f[now] == start)
        {
            if (depth - visited[f[now]] + 1 > maxCycleLen)
                maxCycleLen = depth - visited[f[now]] + 1;
        }
    }
}

void dfs2(int now, int depth, int& maxdepth)
{
    visited[now] = depth;
    if (depth > maxdepth)
        maxdepth = depth;
    for (int i = 1; i <= n; i++)
        if (visited[i] == -1 && f[i] == now)
            dfs2(i, depth + 1, maxdepth);
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("A.txt","w",stdout);
    int t, kase = 0;
    cin >> t;
    while (t--)
    {
        maxCycleLen = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> f[i];
        for (int i = 1; i <= n; i++)
        {
            memset(visited, -1, sizeof(visited));
            dfs(i, i, 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (f[i] == j && f[j] == i)
                {
                    memset(visited, -1, sizeof(visited));
                    int d1 = 0, d2 = 0;
                    visited[i] = visited[j] = 1;
                    dfs2(i, 1, d1);
                    dfs2(j, 1, d2);
                    ans += d1 + d2;
                }
            }
        }
        cout << "Case #" << ++kase << ": " << max(ans, maxCycleLen) << endl;
    }
    return 0;
}
