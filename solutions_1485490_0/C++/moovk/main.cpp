#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

const int maxn = 110;

int n, m;
pair <ll, ll> A[maxn];
pair <ll, ll> B[maxn];
ll dp[maxn][maxn];
int T;
void input1()
{
    scanf("%d", &T);
}
void input2()
{

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%I64d%I64d", &A[i].second, &A[i].first);
    }

    for(int i = 1; i <= m; i ++)
    {
        scanf("%I64d%I64d", &B[i].second, &B[i].first);
    }
}
void init()
{
    memset(dp, 0, sizeof(dp));
}
void AC()
{
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            ll tmp = 0;
            if(A[i].first == B[j].first)
            {
                tmp = max(tmp, dp[i - 1][j - 1] + min(A[i].second, B[j].second));

                for(int i2 = i; i2 >= 1; i2 --)
                {
                    for(int j2 = j; j2 >= 1; j2 --)
                    {
                        ll tmp_A = A[i].second;
                        ll tmp_B = B[j].second;
                        for(int k = i2; k < i; k ++)
                        {
                            if(A[i].first == A[k].first)
                            {
                                tmp_A += A[k].second;
                            }
                        }
                        for(int k = j2; k < j; k ++)
                        {
                            if(B[j].first == B[k].first)
                            {
                                tmp_B += B[k].second;
                            }
                        }
                        tmp = max(tmp, dp[i2 - 1][j2 - 1] + min(tmp_A, tmp_B));
                    }
                }
            }
            tmp = max(tmp, dp[i - 1][j]);
            tmp = max(tmp, dp[i][j - 1]);
            dp[i][j] = tmp;
        }
    }

}
void output(int t)
{
    printf("Case #%d: %I64d\n", t, dp[n][m]);
}
int main()
{
    freopen("in","r",stdin);
    freopen("out.txt","w",stdout);
    input1();


    for(int t = 1; t <= T; t ++)
    {
        input2();

        init();
        AC();
        output(t);

    }
    return 0;
}
