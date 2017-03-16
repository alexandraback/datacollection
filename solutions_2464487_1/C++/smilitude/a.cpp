/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-27 Sat 09:45 AM    
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
#define FOR(i,a,b) for(double i=a; i<=b; i++)
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

bool works( double i, long long t, long long r ) {
    return !( 2*i*i-i + 2*r*i > t );
}

int main() {
    int t;
    scanf("%d",&t);

    while(t--) {
        LL r, a, ans;
        cin >> r >> a;

        LL l = 0, h = a, m;
        while( l <= h ) {
            m = (l+h) / 2;
            if( works( m, a, r) )
                l = m+1;
            else 
                h = m-1;
        }
        print( l-1 );
    }

    return 0;
}

