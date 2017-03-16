#include <cstdio>
#include <set>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

int r, n, m, k;

typedef long long llong;

map<llong, map<vector<int>, int > > M;
set<vector<int> > T;
void init()
{
    int mx = 1;
    for (int i = 0; i < n; i++)
        mx *= (m - 1);
    vector<int> r(n);
    for (int msk = 0; msk < mx; msk++)
    {
        int _msk = msk;
        for (int i = 0; i < n; i++)
            r[i] = msk % (m - 1) + 2, msk /= m - 1;
        for (int gmsk = 0; gmsk < (1 << n); gmsk++)
        {
            llong p = 1;
            for (int i = 0; i < n; i++)
                if ((gmsk >> i) & 1)
                    p = p * r[i];
            M[p][r]++;
        }
        T.insert(r);
        msk = _msk;
    }
}

void solve(int tc)
{
    map<vector<int>, double> P;
    for (set<vector<int> >::iterator it = T.begin(); it != T.end(); it++)
        P[*it] = 1;
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        for (set<vector<int> >::iterator it = T.begin(); it != T.end(); it++)
            P[*it] *= M[t][*it];
    }
    vector<int> mxv;
    double mx = -1;
    for  (map<vector<int>, double>::iterator it = P.begin(); it != P.end(); it++)
        if (mx < it->second)
            mx = it->second, mxv = it->first;
    for (int i = 0; i < n; i++)
        printf("%d", mxv[i]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d", &T);
    scanf("%d %d %d %d", &r, &n, &m, &k);
    assert(T == 1);
    init();
    printf("Case #1:\n");
    for (int i = 0; i < r; i++)
    {
        solve(i + 1);
    }
}
