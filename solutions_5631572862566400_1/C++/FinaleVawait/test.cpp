/*
 * Author:  vawait
 * Created Time:  2016/4/16 10:34:55
 * Problem: test.cpp
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
int n , vis[1100] , p[1010] , dis[1010][1010] , f[1010];
vector < int > g[1100];

void dfs(int n,int t,int d)
{
    int x = p[t];
    dis[n][t] = d;
    if ( !vis[x] ) {
        vis[x] = 1;
        dfs( n , x , d + 1 );
    }
}

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&p[i]);
    clr( dis , 0 );
    rep(i,1,n) {
        clr( vis , 0 );
        dfs( i , i , 0 );
    }
}

void work()
{
    int x , ans = 0 , sum = 0;
    rep(i,1,n) ans = max( ans , dis[i][i] );
    clr( f , 0 );
    rep(i,1,n) if ( !f[i] && i == p[x=p[i]] ) {
        f[i] = x;
        f[x] = -1;
        p[i] = i;
        p[x] = x;
    }
    clr( dis , 0 );
    rep(i,1,n) {
        clr( vis , 0 );
        dfs( i , i , 0 );
    }
    rep(i,1,n) if ( f[i] > 0 ) {
        int mx1 = 0 , mx2 = 0;
        x = f[i];
        rep(j,1,n) if ( j != i && j != x ) mx1 = max( mx1 , dis[j][i] );
        rep(j,1,n) if ( j != i && j != x ) mx2 = max( mx2 , dis[j][x] );
        sum += mx1 + mx2 + 2;
    }
    ans = max( sum , ans );
    printf("%d\n",ans);
}

int main()
{
    //freopen("a.out","w",stdout);
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
