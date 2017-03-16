/*
 * Author:  chlxyd
 * Created Time:  2014/5/4 0:45:45
 * File Name: B.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
long long dp[40][2][2][2] ;
int v[3][100] ;
int T ;
long long a , b , k ;
void did( int x , int i ) {
    int p = 0 ;
    while ( x ) {
        v[i][++p] = x % 2 ;
        x /= 2 ;
    }
}
long long dfs( int p , int a , int b , int c ) {
    if ( dp[p][a][b][c] != -1 ) return dp[p][a][b][c] ;
    if ( p == 1 ) return 1 ;
    dp[p][a][b][c] = 0 ;
    int da , db , dc ;
    rep( i , 2 ) {
        if ( i > v[0][p-1] && a == 1 ) continue ;
        if ( i == v[0][p-1] ) da = a & 1 ;
        else if ( i < v[0][p-1] ) da = a & 0 ;
        rep( j , 2 ) {
            if ( j > v[1][p-1] && b == 1 ) continue ;
            if ( j == v[1][p-1] ) db = b & 1 ;
            else if ( j < v[1][p-1] ) db = b & 0 ;
            rep( k , 2 ) {
                if ( k > v[2][p-1] && c == 1 ) continue ;
                if ( k == v[2][p-1] ) dc = c & 1 ;
                else if ( k < v[2][p-1] ) dc = c & 0 ;
                //cout<<p<<" "<<a<<" "<<b<<" "<<c<<endl ;
                //cout<<da<<" "<<db<<" "<<dc<<" "<<endl;
                if ( (i & j) == k ) {
                    dp[p][a][b][c] += dfs(p-1,da,db,dc) ;
                }
            }    
        }
    }
     //cout<<"dp"<<" "<<p<<" "<<a<<" "<<b<<" "<<c<<" "<<dp[p][a][b][c]<<endl;
   
    return dp[p][a][b][c] ;
}
int main(){
    freopen("B.out","w",stdout) ;
    scanf("%d" , &T  ) ;
    repf( t  , 1 , T  ) {
        clr(v) ;
        scanf("%lld %lld %lld" , &a , &b , &k ) ;
        a -- ; b -- ; k -- ;
        clrs(dp,-1) ;
        did(a,0) ; did(b,1) ; did(k,2) ;
        printf("Case #%d: %lld\n" , t , dfs( 35 , 1 , 1 , 1 ) ) ;
    }
}

