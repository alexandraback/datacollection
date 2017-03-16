#include <climits>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

/*
ll modpow( ll x , ll n ) {
	if( n == 0 ) return 1LL;
	ll ret = f( x , n/2 );
	ret = ret*ret;
	if(n&1) ret = ret*x;
	return ret;
}

ll sse( ll n ) {
	ll nn = n/2;
	ll ret  = ((nn)*(nn+1)*(2n+1))/6;
	ret = 4*ret;
	return ret;
}
ll sst( ll n ) {
	ll ret  = ((n)*(n+1)*(2n+1))/6;
	return ret;
}
ll sso( ll n ) {
	ll ret = sst(n)-sse(n);
	return ret;
}*/
void Solve(){
	ll r , t;
	cin >> r >> t;
	ll l = 0 , h =2*min( (1e18)/(r) , 1e9 );
	while( l < h ) {
		ll mid = (l+h)/2;
		ll tot = 2*(r)*(mid)+2*((mid)*(mid)) - mid;
		if( tot > t ) h = mid;
		else l = mid+1;
	}
	cout << l-1 << "\n";
}
int main() {
	int T  , cs = 1;
	cin >> T;
	while( cs <= T ) {
		cout << "Case #" << cs++ <<": ";
		Solve();
	}
	return 0;
}
