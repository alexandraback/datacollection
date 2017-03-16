/*
 * Author:  Eyelids
 * Created Time:  2014/5/11 17:26:15
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
typedef long long LL;
const LL mod = 1000000007LL;
int T; 
int n;
char s[110][110], st[110];
vector < pair<int, int> > p;
int ban[30], sum[30], x[30], y[30];
int nxt[110], ss[30];
LL tmp; 
LL Calc( int n ) {
    LL ret = 1;
    for ( LL i = 1; i <= n; i ++ )
        ret = ret * i % mod;
    return ret;
}
void Dfs( int u ) {
    //cout <<u<<" "<<p[u].first<<" "<<p[u].second<<endl;
    
    for ( int i = 0; i < (int)p.size(); i ++ ) {
        if ( ban[i] ) continue;
        if ( p[i].first == p[u].second ) {
            nxt[u] = i;
            ban[i] = true;
            Dfs( i ); 
            return;
        }
    }
}

int main(){
    freopen( "B.out", "w", stdout );
    
    scanf( "%d", &T );
    int cas = 0;
    while ( T -- ) {
        scanf( "%d", &n );
        memset( s, 0, sizeof(s) );
        for ( int i = 0; i < n; i ++ ) {
            scanf( "%s", st );
            int len = strlen( st );
            s[i][0] = st[0];
            int tmp = 1;
            for ( int j = 1; j < len; j ++ )
                if ( st[j] != st[j - 1] ) s[i][tmp ++] = st[j];
        }
        memset( ban, 0, sizeof(ban) );
        memset( sum, 0, sizeof(sum) );
        p.clear();
        bool flag = true;
        for ( int i = 0; i < n; i ++ ) {
            int len = strlen( s[i] );
            if ( s[i][0] != s[i][len - 1] ) 
                p.push_back( make_pair( (int)s[i][0] - 'a', (int)s[i][len - 1] - 'a' ) );
            else {
                sum[s[i][0] - 'a'] ++;
            }

            if ( len >= 3 && s[i][0] == s[i][len - 1] ) flag = 0;
            for ( int j = 1; j < len - 1; j ++ ) {
                /*if ( s[i][j] != s[i][0] && s[i][j] != s[i][len - 1] ) {
                    ban[s[i][j] - 'a'] = 1;
                }*/
                ban[s[i][j] - 'a'] = 1;
            }
        }
       
        memset( ss, 0, sizeof(ss) );
        for ( int i = 0; i < n; i ++ ) {
            int len = strlen( s[i] );
            ss[s[i][0] - 'a'] ++;
            for ( int j = 1; j < len; j ++ )
                if ( s[i][j] != s[i][j - 1] ) ss[s[i][j] - 'a'] ++;
        }
        for ( int i = 0; i < 26; i ++ ) {
            if ( ban[i] && ss[i] > 1 ) flag = false;
        }

        memset( x, 0, sizeof(x) );
        memset( y, 0, sizeof(y) );
        for ( int i = 0; i < (int)p.size(); i ++ ) {
            int a = p[i].first, b = p[i].second;
            if ( a == b ) continue;
            x[a] ++, y[b] ++;
        }
        for ( int i = 0; i < 26; i ++ ) {
            if ( x[i] > 1 || y[i] > 1 ) {
                flag = false; 
            } 
        }

        printf( "Case #%d: ", ++ cas );
        LL ret = 0;
        if ( flag ) {
            memset( nxt, -1, sizeof(nxt) );
            for ( int i = 0; i < (int)p.size(); i ++ ) {
                memset( ban, 0, sizeof(ban) );
                Dfs( i );
            }
            
            LL cnt = 0;
            bool flag2 = false;
            for ( int i = 0; i < (int)p.size(); i ++ ) {
                //cout <<p[i].first<<" "<<p[i].second<<" ";
                //cout <<nxt[i]<<endl;;
                if ( nxt[i] == -1 ) {
                    cnt ++;
                    for ( int j = 0; j < (int)p.size(); j ++ )
                        if ( p[i].second == p[j].first ) flag2 = true;
                }
            }

            for ( int i = 0; i < 26; i ++ )
                if ( (sum[i] > 0 && ( ((x[i] == 0) && (y[i] == 0) )) ))  {
                    cnt ++;
                }
            
            ret = Calc( cnt );
            for ( int i = 0; i < 26; i ++ )
                ret = ret * Calc( sum[i] ) % mod;
            
            if ( flag2 )
                cout <<0<<endl;
            else
                cout <<ret<<endl;
        } else {
            cout <<0<<endl;
        }
    }
    
    return 0;
}







