#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
#define SZ(v) ((int)(v).size())
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repf(i, a, b) for (long long i = (a); i <= (b); ++i)
#define repd(i, a, b) for (long long i = (a); i >= (b); --i)
long long b[5][5] = { {0,0,0,0,0},
                {0,1,2,3,4},
                {0,2,-1,4,-3},
                {0,3,-4,-1,2},
                {0,4,3,-2,-1}} ;
long long a[300000] ;
long long n , T , l ; 
char s[110000] ;
int main() {
    freopen("C.out","w",stdout) ;
    scanf("%lld" , &T ) ;
    repf( t , 1, T ) {
        scanf("%lld %lld" , &n , &l ) ;
        scanf("%s" , s ) ;
        rep( i , n ) {
            if ( s[i] == 'i' ) a[i+1] = 2 ;
            else if ( s[i] == 'j' ) a[i+1] = 3 ;
            else if ( s[i] == 'k' ) a[i+1] = 4 ;
        }
        if ( l > 12 )
            l = l % 12 + 12 ;
        repf( i , 1 , l ) {
            repf( j , 1 , n ) 
                a[j+i*n] = a[j] ;
        }
        n *= l ;
        long long okx = -1 , oky = -1 ;
        long long now = 1 ;
        bool pass = true ;
        repf( i , 1 , n ) {
            //cout<<now<<" "<<a[i]<<" ";
            if ( now > 0 )
                now = b[now][a[i]] ;
            else now = -b[-now][a[i]] ;
            //cout<<now<<endl;
        }
        if ( now != -1 ) pass = false ;
        now = 1 ;
        repf( i , 1 , n ) {
            if ( now > 0 )
                now = b[now][a[i]] ;
            else now = -b[-now][a[i]] ;
            if ( now == 2 ) {
                okx = i ;
                break ;
            }
        }
        now = 1 ;
        repd( i , n , 1 ) {
            if ( now > 0 )
                now = b[a[i]][now] ;
            else now = -b[a[i]][-now] ;
            if ( now == 4 ) {
                oky = i ;
                break ;
            }
        }
        if ( okx == -1 || oky == -1 ) pass = false ;
        else if ( okx >= oky-1 ) pass = false ;
        printf("Case #%lld: %s\n" , t , pass?"YES":"NO") ;
    }
    return 0;
}

