#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>

#define ll long long
#define ull unsigned long long
#define all(v)  v.begin() , v.end()
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 1000005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

int n;
vector< vector< int > > memo;
vector< int >v;
int A ;
int dp( int pos , int s )
{
	if( pos == n )return 0;
	int &dev = memo[pos][s];
	if( dev == -1 )
	{
		if( s > v[pos] )dev = dp( pos + 1 , min( N - 2 , s + v[pos]) );
		else {
			dev = 1 + dp( pos + 1 , s ) ;
			if( s != 1 )
			dev = min( dev , 1 + dp( pos , min( N - 2, s + s - 1) ) );
		}
	}
	return dev;
}
int main()
{
	int tc;
	cin >> tc;
	for( int t = 0 ; t < tc ; ++t )
	{
		cin >> A >> n;
		v.resize( n );
		memo.resize( n );
		for( int i = 0 ; i < n ; ++i )
			cin >> v[i], memo[i] = vector< int >(N,-1);
		sort( all(v) );
		cout << "Case #" << t + 1 << ": " << dp( 0 , A ) << endl;
	}
}
