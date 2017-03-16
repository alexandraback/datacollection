/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-13 Sat 12:53 PM    
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

char g[4][5];

bool check( char ch ) {
    REP(i,4) {
        bool ok = 1;
        REP(j,4) if( g[i][j] != ch && g[i][j] != 'T' ) ok = 0;
        if( ok ) return 1;
    }
    
    REP(i,4) {
        bool ok = 1;
        REP(j,4) if( g[j][i] != ch && g[j][i] != 'T'  ) ok = 0;
        if( ok ) return 1;
    }

    bool ok = 1;
    REP(j,4) if( g[j][j] != ch && g[j][j] != 'T' ) ok = 0;
    if( ok ) return 1;
    
    ok = 1;
    REP(j,4) if( g[j][3-j] != ch && g[j][3-j] != 'T' ) ok = 0;
    if( ok ) return 1;
    
    return 0;
}

int main() {
    int t;
    cin >> t;

    FOR(ncase,1,t) {
        REP(i,4) cin >> g[i];
        int xwon = 0, owon = 0, unfinished = 0;
        
        xwon = check( 'X' );
        owon = check( 'O' );
        REP(i,4) REP(j,4) if( g[i][j] == '.' ) unfinished = 1;
       
        printf("Case #%d: ", ncase);

        if( xwon ) printf("X won\n");
        else if( owon ) printf("O won\n");
        else if( unfinished ) printf("Game has not completed\n");
        else printf("Draw\n");
    }

    return 0;
}

