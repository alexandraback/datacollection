#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#define ull unsigned long long
using namespace std;

int dp[2000000];

int reverse( int t )
{
    int ret = 0;
    while( t > 0 )
    {
        ret = ret * 10 + t % 10;
        t /= 10;
    }
    return ret;
}

int bfs(int n)
{
    queue<int>q;
    q.push( 1 );
    memset( dp,0, sizeof( dp ) );
    dp[1] = 1;

    while( !q.empty() )
    {
        int t = q.front();
        q.pop();
        if( t > n ) continue;

        int xt = reverse( t );
        if( dp[xt] == 0 )
        {
            dp[xt] = dp[t] + 1;
            q.push( xt );
        }
        xt = t + 1;
        if( dp[xt] == 0 )
        {
            dp[xt] = dp[t] + 1;
            q.push( xt );
        }
    }
    return dp[n];
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    for( int c = 0;c < t; ++c )
    {
        int n;
        cin>>n;
        printf("Case #%d: %d\n",c+1, bfs(n));

    }
}
