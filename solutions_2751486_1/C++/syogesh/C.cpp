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

bool isvowel( char ch ) {
	if( (ch == 'a') || (ch == 'e') || (ch =='i') || (ch == 'o') || (ch=='u') ) return 1;
	return 0;
}

#define MAXL 1000001
int L[MAXL] , next[MAXL];
void Solve() {
	int N; string s;
	cin >> s; cin >> N;
	int sz = SZ(s);
	CLEAR( L , 0 );

	for( int i = sz-1; i>= 0; i-- ) {
		if( !isvowel( s[i] ) ) L[i] = (L[i+1]+1);
		else L[i]= 0;
	}
	next[sz]=sz;
	for( int i = sz-1; i>= 0; i-- ) {
		if( L[i] >= N ) next[i] = i+N-1; 
		else next[i] = next[i+1];
	}

	ll ans = 0;
	for( int i = 0; i < sz; i++ ) {
		ll tot =  sz-next[i];
		ans += tot;
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