/*
TASK:  
ALGO:
LANG: C++
USER: smilitude
DATE: 2012-05-06 Sun 05:04 PM    
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<cassert>
#include<climits>
using namespace std;

#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define FOR(i,a,b) for(int i(a), _e(b); i<=_e; i++)
#define FORD(i,a,b) for(int i(a), _e(b); i>=_e; i--) 
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )

#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) if(1) cout << __LINE__ <<" "<< #x " = " << (x) \
    <<", " << #y " = " << (y) << endl;

#define M 1005
VI e[M];
int vis[M];

void dfs( int p ) {
    if( vis[p] == 2 ) return;
    vis[p] ++;
    REP(i,e[p].sz) dfs( e[p][i] );
}

int main() {
    int t, n, ncase = 0;
    cin >> t;

    while( t-- ) {
        cin >> n;

        REP(i,M) e[i].clear();
        
        FOR(i,1,n) {
            int total;
            cin >> total;
            REP(k,total) {
                int a;
                cin >> a;
                e[i].pb( a );
            }
        }
        
        bool yes = 0;
        FOR(i,1,n) {
            SET(vis,0);
            dfs(i);
            FOR(k,1,n) if( vis[k] == 2 ) {
                yes = 1;
                break;
            }
        }

        if( yes ) printf("Case #%d: Yes\n", ++ncase );
        else printf("Case #%d: No\n", ++ncase );

    }

    return 0;
}

