#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<30)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define fi first
#define se second
#define MOD 1000000007
#define N 1000000

int t[100][N+1] , n , A[101];

int f(int pos,int x){
    if( pos == n ) return 0;
    int &ret = t[pos][x];
    if( ret != -1 ) return ret;
    ret = inf;
    if( A[pos] < x ) ret = f( pos + 1 , min( 1000000 , x + A[pos] ) );
    else ret = 1 + f( pos + 1 , x );
    ret = min( ret , 1 + f( pos , min( 1000000 , 2 * x - 1 ) ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    for(int k = 1 ; k <= tc ; k++){
        printf("Case #%d: ",k);
        int x;
        sc(x);
        sc(n);
        for(int i = 0 ; i < n ; i++)
            sc(A[i]);
        
        sort( A , A + n );
        
        for(int i = 0 ; i < n ; i++)
            memset( t , -1 , sizeof(t) );

        if( x != 1 ) cout << f( 0 , x ) << endl;
        else cout << n << endl;
    }
}
