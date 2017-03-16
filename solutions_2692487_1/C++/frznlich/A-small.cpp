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

int ar[100+5];
int a,n;

int srch(int idx, int mote){
	if(mote > ar[n-1]) return 0;
	if(idx == n) return 0;
	if(ar[idx] < mote){
		return srch(idx+1,mote+ar[idx]);
	}
	int ret = n-idx;
	for(int i = 1, pow = 2; i < n ; i++, pow*=2){
		if(pow*(mote-1)+1 <= ar[idx]) continue;
		int k = srch(idx+1,pow*(mote-1)+1+ar[idx])+i;
		ret = min(ret, k);
		i++;
		pow *= 2;
	}
	return ret;
}

int main(){
	int tc;
	scanf("%d",&tc);
	REP(tci,1,tc+1){
		scanf("%d%d",&a,&n);
		RESET(ar,-1);
		REP(i,0,n) scanf("%d",&ar[i]);
		sort(ar,ar+n);
		printf("Case #%d: %d\n",tci,srch(0,a));
	}
	return 0;
}
