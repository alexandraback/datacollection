/*
 * Author:  chlxyd
 * Created Time:  2013/5/5 1:14:14
 * File Name: b.cpp
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
int x , y , n , T ;
double dp[16][30] ;
int main(){
    freopen("B.out","w",stdout) ;
    scanf("%d" ,&T ) ;
    repf( t , 1 , T) {
    	clr(dp) ;
        scanf("%d %d %d" , &n , &x , &y ) ;
        int first = 0 ;
        int now = 1 ;
        while ( n > now ) {
        	n -= now ;
            now += 4 ;
            first += 2 ;
        }
		//cout<<abs(x)+abs(y)<<" "<<first<<endl;
        if ( abs( x ) + abs( y ) > first ) {
            printf("Case #%d: %.8lf\n" , t , 0.0 ) ;
            continue ;
        }
        else if ( abs( x ) + abs( y ) < first ) {
            printf("Case #%d: %.8lf\n" , t , 1.0 ) ;
            continue ;
        }
        if ( x == 0 ) {
        	if ( n == now )
            	printf("Case #%d: %.8lf\n" , t , 1.0 ) ;
            else 
            	printf("Case #%d: %.8lf\n" , t , 0.0 ) ;
            continue ;
        }
        int p = ( first - abs(x) ) + 1 ;
        //cout<<first<<" "<<p<<endl;
        dp[0][0] = 1.0 ;
        double ans = 0 ;
		repf( i , 1 , n ) {
			if ( i <= ( now - 1 ) / 2 )
				dp[i][0] = dp[i-1][0] * 0.5 ;
            repf( j , 1 , n ) {
                if ( i - j < (now-1)/2 )
                    dp[i][j] = dp[i-1][j] * 0.5 + dp[i-1][j-1] * 0.5 ;
                else if ( i - j == ( now-1)/2 ) dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * 0.5 ;
                else dp[i][j] = dp[i-1][j-1] ;
				if ( j == p ) {
					ans += dp[i][j] ;
					dp[i][j] = 0 ;
                }
            }
        }
        printf("Case #%d: %.8lf\n" , t , ans ) ;
    }
}
