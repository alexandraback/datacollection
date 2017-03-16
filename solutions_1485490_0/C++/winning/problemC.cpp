#include<stdio.h>
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<map>
using namespace std;
#define MAX 110

int num, M, t_case;
 
struct type
{
        long long int num;
        long long int ty;
};
 
type a[MAX],b[MAX];
 
long long int dp[MAX][MAX];
bool isfind[MAX][MAX];

long long int count( int x, int xx, int y, int yy ){
        // use x type for fund
        long long int n1[MAX] = {0};
        long long int n2[MAX] = {0};
 
        for( int i = x; i < xx; i++ )
                n1[a[i].ty] += a[i].num;

        for( int i = y; i < yy; i++ )
            n2[b[i].ty] += b[i].num;

        long long int v = 0;
        
        for( int i = 0;i < MAX; i++ )
            v = max( v, min(n1[i], n2[i]));
            
        return v;
}
 
long long int DP(int x, int y){
        if( x == num || y == M ) return 0;
 
        if(isfind[x][y]) return dp[x][y];
 
        dp[x][y] = 0;

        for( int i = x+1; i<=num; i++ )
        {
                for( int j = y+1; j <=M; j++ )
                {
                        long long int v = count(x, i, y, j);
                        dp[x][y] = max( dp[x][y], DP(i, j) + v );
                }
        }
        isfind[x][y] = true;

        return dp[x][y];
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C_out.txt", "w", stdout);

    scanf("%d\n",&t_case);

    for(int Case=1; Case<=t_case; Case++){
        
        memset(dp, 0, sizeof(dp));
        memset(isfind, false, sizeof(isfind));
        
        printf("Case #%d: ",Case);

        scanf("%d %d",&num,&M);
        
        for(int i = 0;i < num; i++ )
            scanf("%lld %lld", &a[i].num, &a[i].ty);
        
        for(int i = 0;i < M; i++ )
            scanf("%lld %lld", &b[i].num, &b[i].ty);
                
        long long int ans = DP(0, 0);
        printf("%lld\n",ans);
    }

    return 0;
}

