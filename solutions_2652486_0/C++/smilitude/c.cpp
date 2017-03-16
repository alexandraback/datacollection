/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-27 Sat 10:22 AM    
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

#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i,a,b) for(int i=a; i>=b; i--) 
#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()

#define sz size()
#define pb push_back

int main() {
    
    int t;
    int r, n, m, k;

    printf("Case #1:\n");
    cin >> t;
    cin >> r >> n >> m >> k;

    while( r-- ) {
        int a[10], done = 0;
        REP(i,k) cin >> a[i];

        FOR(i,2,m) if( !done ) FOR(j,i,m) if( !done ) FOR(k,j,m) {
            int s[] = {i,j,k};
            set<int> seen; 
            REP(mask,1<<3) {
                int product = 1;
                REP(l,3) if( mask & (1<<l) ) 
                    product *= s[l];
                seen.insert( product );
            }
            bool ok = 1;
            REP(l,k) if( seen.find( a[l] ) == seen.end() ) 
                ok = 0;
            if( ok ) {
                printf("%d%d%d\n",i,j,k);
                done = 1;
                break;
            }
        }
    }

    return 0;
}

