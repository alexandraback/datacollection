#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<algorithm>
using namespace std;

typedef long long ll;

inline int soto(int a, int b)
{
    if(a<b)return a;
    return b;
}

int dp[11][1001], vis[11][1001], mem, N, arr[11];

int solve(int p, int sum)
{
    if(p==N)return 0;
    if(vis[p][sum]==mem)return dp[p][sum];

    vis[p][sum] = mem;
    int &ret = dp[p][sum] = N+10;

    if(sum>arr[p])ret=solve(p+1, sum+arr[p]);
    else
    {
        ret = soto(ret, 1+solve(p+1, sum));
        ret = soto(ret, 1+solve(p, sum+(sum-1)) );
    }

    return ret;
}

int main()
{
    freopen("As.in", "r", stdin);
    freopen("AsOut.out", "w", stdout);

    int i, j, T, kas=1, A;

    for(scanf("%d",&T); kas<=T; kas++)
    {
        scanf("%d%d",&A,&N);
        for(i=0; i<N; i++)scanf("%d",&arr[i]);

        sort(arr, arr+N);
        ++mem;
        printf("Case #%d: %d\n",kas,solve(0,A));
    }

    return 0;
}
