/*
TASK:  
LANG: C++
USER: smilitude
DATE: 2013-04-13 Sat 01:59 PM    
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
#define FOR(i,a,b) for(long long i(a), _e(b); i<=_e; i++)
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

bool ispalin( LL a ) {
    char b[100];
    sprintf( b, "%lld", a );
    string s = b;
    string t = s;
    reverse( ALL(t) );
    return s == t;
}

int main() {
    
    vector< LL > v;
    FOR(i,1,10000000) if( ispalin(i) && ispalin( i*i ) ) v.pb( i*i );

    int t;
    cin >> t;

//    REP(i,v.sz) if( v[i] >= 100 && v[i] <= 1000 ) cout << i <<" "<< v[i] << endl;

    FOR(ncase,1,t) {
        LL a, b;
        cin >> a >> b;
        printf("Case #%lld: %d\n", ncase, (int)(upper_bound( ALL(v), b ) - lower_bound( ALL(v), a)) );
    }

    return 0;
}

