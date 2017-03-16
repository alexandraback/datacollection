#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 35

string a , b , c;

string tostring(int x){
    string s = "";
    while( x ){
        int r = x % 2;
        s += '0' + r;
        x /= 2;
    }
    reverse( all(s) );
    return s;
}

void full(string &s,int x){
    while( s.size() != x ){
        s = "0" + s;
    }
}

int L;
ll t[N][2][2][2];

ll f(int x,int m1,int m2,int m3){
    if( x == L ) return m3;
    ll &ret = t[x][m1][m2][m3];
    if( ret != -1 ) return ret;
    ret = 0;
    if( m3 ){
        int p = a[x] - '0' , q = b[x] - '0';
        int u1 = m1?1:p;
        int u2 = m2?1:q;
        for(int i = 0 ; i <= u1 ; i++)
            for(int j = 0 ; j <= u2 ; j++)
                ret += f( x + 1 , m1|(i<p) , m2|(j<q) , m3 );
    }
    else{
        int p = a[x] - '0' , q = b[x] - '0', r = c[x] - '0';
        int u1 = m1?1:p;
        int u2 = m2?1:q;
        for(int i = 0 ; i <= u1 ; i++)
            for(int j = 0 ; j <= u2 ; j++)
                if( (i and j) <= r ) ret += f( x + 1 , m1|(i<p) , m2|(j<q) , ((i and j) < r) );
        
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);
    for(int tt = 1 ; tt <= tc ; tt++){
        printf("Case #%d: ",tt);
        int A , B , K;
        cin >> A >> B >> K; A--,B--;
        a = tostring( A );
        b = tostring( B );
        c = tostring( K );
        int sz = max( a.size() , max( b.size() , c.size() ) );
        full( a , sz );
        full( b , sz );
        full( c , sz );
        L = sz;
        me(t,-1);
        ll ans = f( 0 , 0 , 0 , 0 );
        cout << ans << "\n";
    }
    return 0;
}
