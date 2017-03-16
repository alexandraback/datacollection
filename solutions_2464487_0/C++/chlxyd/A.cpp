/*
 * Author:  chlxyd
 * Created Time:  2013/4/27 9:04:27
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
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
long double r , tt ;
int T ;
int sgn( long double x ) {
	return ( x > eps ) - ( x < - eps ) ;
}
bool pass( long double num ) {
    long double now = ( 2 * r - 1 ) * num + 2 * num * num ;
    //cout<<now-tt<<endl;
    return sgn(now - tt)<=0 ;
}
long long solve() {
    long long l = 1 , r = 10000000000LL ;
    while ( l < r ) {
        long long mid = ( l + r ) / 2 ;
        if ( pass( (long double)mid ) ) 
            l = mid ;
        else r = mid ;
        if ( r - l == 1 ) {
            if ( pass((long double)r) ) return r ;
            else if ( pass((long double)l) ) return l ;
        }
    }
    return r ;
}
int main(){
    freopen("A.out","w",stdout);
    scanf("%lld" ,&T ) ;
    repf( t , 1 , T ) {
        cin>>r>>tt;
		printf("Case #%lld: %lld\n" , t , solve() ) ;
    }
}

