/*
TASK:  
ALGO:
LANG: C++
USER: smilitude
DATE: 2012-05-06 Sun 05:24 PM    
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
int na, nb;
LL a[M], b[M];
int A[M], B[M];
LL m[M][M];

LL f(int ta, int tb) {
    if( ta == na ) return 0;
    if( tb == nb ) return 0;
    
    LL& ret = m[ta][tb];
    if( ret != -1 ) return ret;
   
    // no picking
    ret = max( f(ta+1,tb), f(ta, tb+1) ); 

    // let's pick ta
    LL totala = 0, totalb = 0;
    FOR(j,ta,na-1) {
        if( A[j] == A[ta] ) totala += a[j];
        FOR(i,tb,nb-1) {
            if( B[i] == A[ta] ) totalb += b[i];
            ret = max( ret, min( totalb, totala ) + f(j+1,i+1) );
        }
        totalb = 0;

    }

    // let's pick tb
    totala = 0, totalb = 0;
    FOR(j,tb,nb-1) {
        if( B[j] == B[tb] ) totalb += b[j];
        FOR(i,ta,na-1) {
            if( A[i] == B[tb] ) totala += a[i];
            ret = max( ret, min( totala, totalb ) + f(i+1,j+1) );
        }
        totala = 0;
    }

    return ret;
}

int main() {
    int t, ncase = 0;
    
    cin >>t;
    while( t-- ) {
        cin >> na >> nb;
        REP(i,na) cin >> a[i] >> A[i];
        REP(i,nb) cin >> b[i] >> B[i];
        
        SET(m,-1);
        printf("Case #%d: %lld\n", ++ncase, f(0,0) );
    }

    return 0;
}

