#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1024

int n;
int marca;
int m[MAXN];
int g[MAXN];
int p[MAXN];

bool achou;

vector<int> adj[MAXN];

void busca(int i)
{
    p[i] = marca;
    if (achou) return;

    for (int j = 0; j < (int) adj[i].size(); ++j)
    {
        if (p[adj[i][j]] == marca) achou = true;
        else busca(adj[i][j]);
    }
}

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d: ", caso);

        scanf ("%d", &n);
        memset(g, 0, sizeof(g));

        for (int i = 0; i < n; ++i)
        {
            adj[i].clear();
        }

        for (int i = 0; i < n; ++i)
        {
            scanf ("%d", &m[i]);

            for (int j = 0; j < m[i]; ++j)
            {
                int x;
                scanf ("%d", &x);
                --x;

                adj[x].push_back(i);
                ++g[i];
            }
        }

        /*
        for (int i = 0; i < n; ++i)
        {
            printf ("%d: ", i+1);
            for (int j = 0; j < (int) adj[i].size(); ++j)
            {
                printf ("%d ", adj[i][j]+1);
            }
            printf ("\n");
        }
        */

        memset(p, 0, sizeof(p));

        marca = 1;
        achou = false;
        for (int i = 0; i < n; ++i)
        {
            if (g[i] == 0)
            {
                busca(i);
                ++marca;
            }
        }

        if (achou)
        {
            printf ("Yes\n");
        }
        else
        {
            printf ("No\n");
        }
    }

    return 0;
}

