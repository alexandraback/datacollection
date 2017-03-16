#include <bits/stdc++.h>

using namespace std;

int v[1003];
vector<int> p[1003];
int prof[1003];
int qu[1003];
int ret2;
pair<int, int> aquele;
int dfs(int atual, int pf, int qual, int quem)
{
    if (qu[atual] == qual)
    {
        if (pf - prof[atual] == 2)
        {
            aquele.first = atual;
            aquele.second = quem;
        }
        return pf - prof[atual];
    }
    if (qu[atual] != 0)
        return -1;
    qu[atual] = qual;
    prof[atual] = pf;
    int ret = dfs(v[atual], pf + 1, qual, atual);

    if (ret == -1)
        return -1;
    return ret;
}
int dfs2(int atual, int pf)
{
    int mx = 0;
    for (int i = 0; i < p[atual].size(); i++)
    {
        if (p[atual][i] != aquele.first && p[atual][i] != aquele.second)
            mx = max(mx, dfs2(p[atual][i], pf + 1) + 1);
    }
    return mx;
}
int main()
{
    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++)
    {
        ret2 = 0;
        cout << "Case #" << ti + 1 << ": ";
        memset(v, 0, sizeof(v));

        for (int i = 0; i < 1003; i++)
            p[i].clear();

        memset(prof, -1, sizeof(prof));
        memset(qu, 0, sizeof(qu));
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            int in;
            cin >> in;
            v[i] = in;
            p[in].push_back(i);
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int ret = dfs(i, 0, i, -1);

            if (ret == 2)
            {
                int aux = dfs2(aquele.first, 0);
                aux += dfs2(aquele.second, 0);
                aux += 2;
                ret2 += aux;
                ret = max(ret, ret2);

            }
            if (ret != -1)
                res = max(res, ret);
        }
        cout << res << endl;
    }

}

