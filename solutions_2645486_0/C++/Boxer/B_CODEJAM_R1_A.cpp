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

#define inf (1<<30)
#define eps 1e-5
#define ll long long
#define all(v)  v.begin() , v.end()
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define test puts("test");

#define N 105
#define MOD 1000000007

using namespace std;

int E , R , n ;
int v[N];
int memo[N][N*N];

int dp( int pos , int ener )
{
	if( pos == n )return 0;
	int &dev = memo[pos][ener];
	if( dev == -1 )
	{
		dev = 0 ;
		for( int i = 0 ; i <= ener ; ++i )
			dev = max( dev , i*v[pos] + dp( pos + 1 , min( E , ener - i + R ) ) );
	}
	return dev;
}
int main()
{
	int tc;
	cin >> tc;
	for( int t = 0 ; t < tc ; ++t )
	{
		cin >> E >> R >> n ;
		for( int i = 0 ; i < n ; ++i )cin >> v[i];
		me( memo , -1 );
		cout << "Case #" << t + 1 << ": " << dp( 0 , E ) << endl;
	}
}
