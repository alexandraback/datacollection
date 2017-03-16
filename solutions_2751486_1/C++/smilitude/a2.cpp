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

char word[1000005];

int main() {
    int t;
    scanf("%d",&t);

    while( t-- ) {
        int n, len;
        long long ans = 0;

        scanf("%s %d", word, &n );
        len = strlen( word );
        REP(i,len) word[i] = okay( word[i] );

//        REP(i,len) cout << int(word[i]);
//        cout << endl;
        
        int score = 0, last = -1;
        REP(i,n) score += word[i];
        if( score == n ) {
            last = 0;
            ans += len - n + 1;
        }
        
        FOR(i,1,len) {
            if( i+n-1 >= len ) break;
            score -= word[i-1];
            score += word[i+n-1];
            
            if( score == n ) {
                long long left, right;
                left = i - last;
                right = len - (i+n-1);
//                cout <<i <<" "<< left <<" "<<right<<endl;
                ans += left * right;
                last = i;
            }
        }

        printf("Case #%d: %lld\n", ++ncase, ans);
    }
    return 0;
}

