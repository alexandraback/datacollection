#include <bitset>
#include <cstdio>
#include <iostream>
using namespace std;

const int nmax = 1100, mmax = 10010;

int nodeV[mmax], nextE[mmax], n, cnt, indE[nmax], cnte[nmax];
bool visited[nmax];

//return void
void EdgeAppend(int u, int v)
{
    cnt++;
    nodeV[cnt] = v, nextE[cnt] = indE[u];
    indE[u] = cnt;
}

bool search(int u)
{
    visited[u] = true;
    cnte[u]++;
    if (cnte[u] == 2)
        return true;

	//comment
    int edge  = indE[u];
    while (edge > 0)
    {
        int v = nodeV[edge];
        if (search(v))
            return true;
        edge = nextE[edge];
    }
    return false;
}

int main()
{
    int testcase;
    scanf("%d", &testcase);
    for (int test = 1; test <= testcase; test++)
    {
        scanf("%d", &n);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            indE[i] = -1;
            int m;
            scanf("%d", &m);
            for (int j = 1; j <= m; j++)
            {
                int v;
                scanf("%d", &v);
                EdgeAppend(i, v);
            }
            visited[i] = false;
        }
        bool diamond = false;
        for (int i = 1; !diamond && i <= n; i++)
            if (!visited[i])
            {
                for (int j = 1; j <= n; j++)
                    cnte[j] = 0;
                if (search(i))
                    diamond = true;
            }
        if (diamond)
            printf("Case #%d: Yes\n", test);
        else
           printf("Case #%d: No\n", test);
    }
    return 0;
}

