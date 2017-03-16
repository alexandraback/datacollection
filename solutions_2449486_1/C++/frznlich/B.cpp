// Template
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define fi first
#define sc second
#define MP make_pair
#define pb push_back
#define PI acos(-1.0) //alternative #define PI (2.0 * acos(0.0))
#define vi vector<int>
#define vii vector<pii>
#define ALL(c) (c).begin(), (c).end()
#define RESET( c,a ) memset( (c), a, sizeof(c) )
#define REP( a,b,c ) for ( int a=b, _c=c; a<_c; ++a )
#define RED( a,b,c ) for ( int a=b, _c=c; a>=_c; --a )
#define REPI( it, c ) for ( __typeof( (c).begin() ) it=(c).begin(); it!=(c).end(); ++it )

const int big = 1000000000;
const double INF = 1e9;
const double EPS = 1e-9;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

bool process(){
	int n,m;
	scanf("%d%d",&n,&m);
	int ar[n+5][m+5];
	bool br[n+5][m+5];
	RESET(br,0);
	pair<int, pii> st[n*m+5];
	REP(i,0,n){
		REP(j,0,m){
			scanf("%d",&ar[i][j]);
			st[i*m+j] = MP(ar[i][j],MP(i,j));
		}
	}
	sort(st,st+n*m);
	int d,i,j;
	REP(k,0,m*n){
		d = st[k].fi;
		i = st[k].sc.fi;
		j = st[k].sc.sc;
		if(br[i][j]) continue;
		bool row = 1, col = 1;
		REP(l,0,m){
			if(!br[i][l] && ar[i][l] > d){
				row = 0;
			}
		}
		REP(l,0,n){
			if(!br[l][j] && ar[l][j] > d){
				col = 0;
			}
		}
		if(!(row || col)) return 0;
		if(row){
			REP(l,0,m) br[i][l] = 1;
		}
		if(col){
			REP(l,0,n) br[l][j] = 1;
		}
	}
	return 1;
}

int main(){
	int tc;
	scanf("%d",&tc);
	REP(tci,1,tc+1){
		bool ret = process();
		if(ret) printf("Case #%d: YES\n",tci);
		else	printf("Case #%d: NO\n",tci);
	}
}

