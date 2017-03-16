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

const int MAXN = 110;

typedef long long LL;

int n, m;
LL a[MAXN];
LL A[MAXN];
LL b[MAXN];
LL B[MAXN];
map<pair<pair<int, int>, pair<int, int> >, LL> dp;
LL dfs(int p1, int p2, LL leftP1, LL leftP2)
{
    if (p1 == n && p2 == m)
    {
        return 0;
    }
    else if (p1 >= n)
    {
        return 0;
    }
    else if (p2 >= m)
    {
        return 0;
    }

    pair<pair<int, int>, pair<int, int> > now = make_pair(make_pair(p1, p2), make_pair(leftP1, leftP2));

    if (dp.find(now) != dp.end())
    {
        return dp[now];
    }
    LL ret = 0;
    if (A[p1] == B[p2])
    {
        if (leftP1 < leftP2)
        {
            ret = max(ret, dfs(p1 + 1, p2, a[p1 + 1], leftP2 - leftP1) + leftP1);
        }
        else if (leftP1 == leftP2)
        {
            ret = max(ret, dfs(p1 + 1, p2 + 1, a[p1 + 1], b[p2 + 1]) + leftP1);
        }
        else
        {
            ret = max(ret, dfs(p1, p2 + 1, leftP1 - leftP2, b[p2 + 1])  + leftP2);
        }
    }
    else
    {
        ret = max(ret, dfs(p1 + 1, p2, a[p1 + 1], leftP2));
        ret = max(ret, dfs(p1, p2 + 1, leftP1, b[p2 + 1]));
    }

    dp[now] = ret;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &a[i], &A[i]);
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%lld%lld", &b[i], &B[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            int j = 0;
            for (j = i + 1; j < n; j++)
            {
                if (A[j] != A[j - 1])
                {
                    break;
                }
                else
                {
                    a[i] += a[j];
                }
            }

            if (j > i + 1)
            {
                for (int k = j; k < n; k++)
                {
                    a[i + 1 + (k - j)] = a[k];
                    A[i + 1 + (k - j)] = A[k];
                }

                n -= (j - i - 1);
            }
        }

        printf("Case #%d: %lld\n", t + 1,         dfs(0, 0, a[0], b[0]));
    }
}

