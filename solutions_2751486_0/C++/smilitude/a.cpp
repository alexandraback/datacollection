/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-05-12 Sun 05:03 PM    
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

int ncase = 0;

bool okay( char ch ) {
    return !( ch == 'a' || ch == 'e' || ch == 'o'
            || ch == 'i' || ch == 'u' );
}

int main() {
    int t;
    scanf("%d",&t);

    while( t-- ) {
        char word[105];
        int n, len, ans = 0;
        
        scanf("%s %d", word, &n );
        len = strlen( word );
        REP(i,len) REP(j,i+1) {
            int slip = 0;
            bool ok = 0;
            FOR(k,j,i) {
                if( okay( word[k] ) ) slip ++;
                else slip = 0;
                if( slip == n ) ok = 1;
            }
            ans += ok; 
        }

        printf("Case #%d: %d\n", ++ncase, ans);

    }
    return 0;
}

