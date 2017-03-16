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
#define ll unsigned long long int
#define ii pair<int,int>
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()

template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}

void Solve() {
	ll A; cin >> A;
	ll N; cin >> N;
	vector<ll> motes; motes.clear();
	rep( i , 0 , N ){ ll x; cin >> x; motes.push_back(x); }
	sort( motes.begin() , motes.end() );

	ll curSize = A;
	ll ans = N;
	rep( i , 0 ,  N+1 ) {
		int j = 0;ll ts = curSize;
		while( j < motes.size() && ( ts > motes[j]) ){  ts += motes[j]; j++; }  
		ans = min( ans , N-j+2*i );
	//	curSize = 2*ts-1;	
		motes.push_back(ts-1);
		sort( motes.begin() , motes.end() );
	}
	cout << ans << "\n";
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