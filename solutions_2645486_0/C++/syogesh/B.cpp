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
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
 
using namespace std;
 
#define rep(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define pb push_back

 
template <class T>inline string itos( T n ) {return (n)< 0?"-"+itos(-(n)):(n)<10?(string)("")+(char('0'+(n))):itos((n)/10)+itos((n)%10);}

int dp[10][10];
vector<int> v;
int f( int i , int e , int &E, int &R , int &N ) {
	if( i == (N-1) ) return (e*v[i]);
	int &ret = dp[i][e];
	if( ret == -1 ) {
		ret = 0;
		rep( j , 0 , e+1 ) ret = max( ret , j*v[i]+f( i+1 , min( e+R-j , E ) , E , R , N ) ); 
	}
	return ret;
}
void Solve() {
	int E , R , N;
	cin >> E >> R >> N;
	v.clear();
	rep( i , 0 , N ) { int x; cin >> x; v.pb(x); }
	CLEAR( dp , -1 );
	int ans = f( 0 , E , E , R , N );
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
