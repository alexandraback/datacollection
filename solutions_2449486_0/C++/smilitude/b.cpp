/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-13 Sat 01:38 PM    
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

#define M 105

int a[M][M], seen[M][M], n, m;

void row(int i, int c) {
    REP(j,m) if( a[i][j] > c ) return;
    REP(j,m) seen[i][j] = 1;
}

void col(int j, int c) {
    REP(i,n) if( a[i][j] > c ) return;
    REP(i,n) seen[i][j] = 1;
}

int main() {
    int t;

    cin >> t;
    FOR(ncase,1,t) {
        cin >> n >> m;
        REP(i,n) REP(j,m) cin >> a[i][j];
    
        bool can = true;
        FORD(c,100,1) {
            SET(seen,0);

            REP(i,n) row(i,c);
            REP(i,m) col(i,c);
            REP(i,n) REP(j,m) if( a[i][j] == c && !seen[i][j] ) {
                can = false;
                break;
            }
        }
        
        printf("Case #%d: %s\n", ncase, (can ? "YES" : "NO"));
    }


    return 0;
}

