// code jam round 1C
//problem A

#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1100, MAXM = 10010;

int nodeV[MAXM], nextE[MAXM], n, cnt, indE[MAXN], counter[MAXN];
bool visited[MAXN];

void addEdge(int u, int v)
{
    cnt++;
    nodeV[cnt] = v, nextE[cnt] = indE[u];
    indE[u] = cnt;
}

bool find(int u)
{
    visited[u] = true;
    counter[u]++;
    if (counter[u] == 2)
        return true;
    int edge  = indE[u];
    while (edge > 0)
    {
        int v = nodeV[edge];
        if (find(v))
            return true;
        edge = nextE[edge];
    }
    return false;
}

int main()
{
    int testcase;
    FILE *fin = fopen("a.in", "r");
    FILE *fout = fopen("a.out", "w");
    fscanf(fin, "%d", &testcase);
    for (int test = 1; test <= testcase; test++)
    {
        fscanf(fin, "%d", &n);
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            indE[i] = -1;
            int m;
            fscanf(fin, "%d", &m);
            for (int j = 1; j <= m; j++)
            {
                int v;
                fscanf(fin, "%d", &v);
                addEdge(i, v);
            }
            visited[i] = false;
        }
        bool diamond = false;
        for (int i = 1; !diamond && i <= n; i++)
            if (!visited[i])
            {
                for (int j = 1; j <= n; j++)
                    counter[j] = 0;
                if (find(i))
                    diamond = true;
            }
        if (diamond)
            fprintf(fout, "Case #%d: Yes\n", test);
        else
            fprintf(fout, "Case #%d: No\n", test);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

