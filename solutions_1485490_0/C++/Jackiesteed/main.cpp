#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <iomanip>




using namespace std;

const int MAXN = 110;
typedef long long LL;
int N, M;
int T;

LL a[MAXN], A[MAXN], b[MAXN], B[MAXN];

LL dp[MAXN][MAXN];

LL record[MAXN][MAXN];
int residue[MAXN][MAXN];

LL DP(int x, int y)
{
    if(-1 != dp[x][y]) return dp[x][y];

    if(x == 0)
    {
        dp[x][y] = min(record[x][y], a[x]);
        return dp[x][y];
    }
    dp[x][y] = min(record[x][y], a[x]);

    for(int i = 0; i <= y; i++)
    {
        dp[x][y] = max(dp[x][y], DP(x - 1, i) + min(a[x], record[x][y] - record[x][i]));
    }
    return dp[x][y];
}

LL work(LL tot, LL id, LL s)
{
    if(id == N - 1)
    {
        LL cnt = 0;
        for(int j = s; j < M; j++)
        {
            if(A[id] == B[j])
            {
                cnt += b[j];
            }
        }
        return min(cnt, tot);
    }
    LL ans = work(a[id + 1], id + 1, s);
    LL cnt = 0;
    for(int j = s; j < M; j++)
    {
        if(A[id] == B[j])
        {
            cnt += b[j];
            ans = max(ans, min(cnt, a[id]) + work(a[id + 1], id + 1, j + 1));
            if(cnt > tot)
            {
                LL left = cnt - tot;
                for(int k = id + 1; k < N; k++)
                {
                    if(A[id] == A[k])
                    {
                        LL add = min(left, a[k]);
                        LL this_tot = a[k] - add;
                        ans = max(ans, tot + add + work(this_tot, k, j + 1));
                    }
                }
                break;
            }
        }
    }

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    for(int ncase = 1; ncase <= T; ncase++)
    {
        cin >> N >> M;

        for(int i = 0; i < N; i++)
        {
            cin >> a[i] >> A[i];
        }
        for(int i = 0; i < M; i++)
        {
            cin >> b[i] >> B[i];
        }
        LL ans = work(a[0], 0, 0);
        cout << "Case #" << ncase << ": ";
        cout << ans << endl;



    }















    return 0;
}

