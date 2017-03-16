#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

#define Pi acos(-1.0)
#define INT_MAX 2147000000
#define mp make_pair
#define pb push_back

using namespace std;

vector <int> a[1050];
bool used[1050];
int n;
bool found;

void dfs(int v)
{
    if (used[v])
    {
        found = 1;
        return;
    }
    used[v] = 1;
    for (int i = 0; i < a[v].size(); i++)
    {
        dfs(a[v][i]);
    }
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            a[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &a[i][j]);
                a[i][j]--;
            }
        }
        found = 0;
        for (int i = 0; i < n && !found; i++)
        {
            memset(used, 0, sizeof(used));
            dfs(i);
        }
        if (!found)
        {
            printf("Case #%d: No\n", tc + 1);
        }
        else
        {
            printf("Case #%d: Yes\n", tc + 1);
        }
    }
}
