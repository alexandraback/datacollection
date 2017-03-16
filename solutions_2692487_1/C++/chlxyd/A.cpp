/*
 * Author:  chlxyd
 * Created Time:  2013/5/5 0:03:50
 * File Name: A.cpp
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
int a , n , T ;
int v[200] ;
int f[200] ;
int solve() {
    if ( a == 1 ) return n ;
    repf( i , 1 , n ) {
        f[i] = f[i-1] ;
        if ( a > v[i] ) 
            a += v[i] ;
        else {
            while ( a <= v[i] ) {
                a = a + ( a - 1 ) ;
                f[i] ++ ;
            }
            a += v[i] ;
        }
    }
    int ret = 1000000 ;
    repf( i , 1 , n ) {
        //cout<<f[i]<<endl;
        if ( ret > f[i] + ( n - i ) ) 
            ret = f[i] + ( n - i ) ;
    }
    ret = min( ret , n ) ;
    return ret ;
}
int main(){
    //freopen("A1.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d" , &T );
    repf( t , 1 , T ) {
        scanf("%d %d" , &a , &n ) ;
        repf( i , 1 , n ) 
            scanf("%d" , &v[i] ) ;
        sort( v + 1 , v + n + 1 ) ;
        printf("Case #%d: %d\n" , t , solve() ) ;
        //return 0 ;
    }
}

