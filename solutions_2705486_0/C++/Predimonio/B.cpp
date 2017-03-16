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
#define N 3323300

int next[ N ][ 26 ] , node , term[ N ] , n;
map< pair<int, pii > , int > t;

void add(char *s){
    int l = strlen(s) , ac = 0;
    for(int i = 0 ; i < l ; i++){
        if( next[ ac ][ s[i] - 'a' ] == -1 ) next[ac][ s[i] - 'a' ] = ++node;
        ac = next[ac][ s[i] - 'a' ];
    }
    term[ac] = 1;
}

char text[55];
int f(int pos,int ac,int x){
    if( pos == n ){
        if( term[ac] ) return 0;
        return inf;
    }
    pair< int , pii  > ret = mp( pos , mp( ac , x ) );
    if( t.find( ret ) != t.end() ) return t[ret];
    int ans = inf;
    int sig = next[ ac ][ text[pos] - 'a' ];
    if( sig != -1 ){
        ans = f( pos + 1 , sig , min( 5 , x + 1 ) );
        if( term[sig] ) ans = min( ans , f(pos + 1 , 0 , min( 5 , x + 1 ) ) );
    }
    if(x == 5 ){
        for(int i = 0 ; i < 26 ; i++){
            if( 'a' + i == text[pos] ) continue;
            sig = next[ ac ][ i ];
            if( sig == -1 ) continue;
            ans = min( ans, 1 + f( pos + 1 , sig , 1 ) );
            if( term[sig] ) ans = min( ans , 1 + f( pos + 1 , 0 , 1 ) );
        }
    }
    t[ret] = ans;
    return ans;
}

int main(){
    char s[55];
    int ans = 0 , S = 0 , node = 1;
    me( next , -1 );
    me( term , 0 );
    for(int i = 0 ; i < 521196 ; i++){
        scanf("%s",s);
        add( s );
    }
    int tc;
    sc(tc);
    for(int k = 1 ; k <= tc ; k++){
        printf("Case #%d: ",k);
        scanf("%s",text);
        n = strlen(text);
        t.clear();
        cout << f( 0 , 0 , 5 ) << endl;
        
    }
    
}
