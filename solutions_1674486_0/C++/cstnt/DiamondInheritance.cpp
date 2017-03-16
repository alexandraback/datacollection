/*
ID: cstnt
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAXN = 1100;

int list[MAXN][MAXN];
int cnt[MAXN];
int color[MAXN];
int n;

bool dfs(int now)
{
    //cout << "DFS " << now << endl;
    color[now] = 1;
    for (int i = 0; i < cnt[now]; i++)
    {
        if (color[list[now][i]] == 0)
        {
            if (dfs(list[now][i]))
            {
                return true;
            }
        }
        else if (color[list[now][i]] == 1)
        {
            throw "Invalid";
        }
        else if (color[list[now][i]] == 2)
        {
            return true;
        }
    }
    color[now] = 2;

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++)
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cnt[i]);
            for (int j = 0; j < cnt[i]; j++)
            {
                scanf("%d", &list[i][j]);
                list[i][j]--;
            }
        }

        bool diamond = false;
        for (int i = 0; i < n & !diamond; i++)
        {
            memset(color, 0, sizeof(color));
            if (dfs(i))
            {
                diamond = true;
            }
        }

        printf("Case #%d: %s\n", t + 1, diamond ? "Yes" : "No");
    }
}
