/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-27 Sat 10:03 AM    
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

typedef long long LL;

int ncase = 0;
void print(LL x) {
    printf("Case #%d: %lld\n", ++ncase, x );
}

#define M 15 
int m[M][M];
int n, e, r, v[M];

int f(int p, int energy) {
    if( p == n ) return 0;
    int& ret = m[p][energy];
    if( ret != -1 ) return ret;

    ret = f(p+1, min( e, energy + r ) );
    FOR(i,1,energy) {
        ret = max( ret, i*v[p] + f(p+1, min( e, energy - i + r ) ) );
    }
    return ret;
}

int main() {
    
    int t;
    cin >> t;

    while( t-- ) {
        SET(m,-1);
        cin >> e >> r >> n;
        REP(i,n) cin >> v[i];
        print( f(0,e) );
    }

    return 0;
}

