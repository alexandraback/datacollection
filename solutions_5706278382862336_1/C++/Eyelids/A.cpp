/*
 * Author:  Eyelids
 * Created Time:  2014/5/11 17:04:04
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
typedef long long LL;
int T;
LL Gcd( LL a, LL b ) {
    return ( a % b == 0 ) ? b : Gcd( b, a % b );
}

int main() {
    freopen( "A.out", "w", stdout );
    
    scanf( "%d", &T );
    int cas = 0;
    char ch;
    while ( T -- ) {
        int tmp = 0;
        LL n, m;
        cin >>n>>ch>>m;
        swap( n, m );
        LL g = Gcd( n, m );
        n /= g, m /= g;
        
        while ( n != 1 ) {
            if ( n % 2 == 0 ) {
                tmp ++;
                n /= 2; 
            } else {
                tmp = -1;
                break;
            }
        }
        int buf = 0;
        while ( m ) {
            m /= 2;
            buf ++; 
        }
       
        printf( "Case #%d: ", ++ cas );
        if ( tmp == -1 ) 
            cout <<"impossible"<<endl;
        else
            cout <<tmp - buf + 1<<endl;
    }
    
    return 0;
}







