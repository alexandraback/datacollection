#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define piii pair<pair<int,int>,int>
#define pii pair<int,int>
#define pdd pair<double,double>
#define MAXPANC 100
#define MAXPAUS 100
#define MAXN 1010

int N, a[MAXN], dp[MAXN][MAXN], ans[MAXN][MAXN];

void Debug()
{
}

void Read()
{
    cin >> N;
    for(int i=1; i<=N; ++i)
        cin >> a[i];
}

void BuildDp()
{
    for(int i=1; i<=MAXPANC; ++i)
    {
        dp[i][0] = i;
        for(int j=1; j<=MAXPAUS; ++j)
        {
            dp[i][j] = dp[i][j-1]+1;
            for(int k=1; k<i; ++k)
            {
                for(int l=0; l<=j-1; ++l)
                    dp[i][j] = min(dp[i][j], max(dp[k][l]+j-1-l, dp[i-k][0]+l)+1);
            }
        }
    }
}

void Solve()
{
    int out = 0x3f3f3f3f;

    for(int i=1; i<=N; ++i)
    {
        for(int j=0; j<=MAXPAUS; ++j)
        {
            ans[i][j] = 0x3f3f3f3f;
            for(int k=0; k<=j; ++k)
            {
                ans[i][j] = min(ans[i][j], max(ans[i-1][k]+j-k, dp[a[i]][j-k]+k));
            }
        }
    }

    for(int i=0; i<=MAXPAUS; ++i)
        out = min(out, ans[N][i]);

    printf("%d\n", out);
}

int main()
{
    int t;
    cin >> t;
    BuildDp();
    for(int i=1; i<=t; ++i)
    {
        Read();
        printf("Case #%d: ", i);
        Solve();
        Debug();
    }
    return 0;
}
