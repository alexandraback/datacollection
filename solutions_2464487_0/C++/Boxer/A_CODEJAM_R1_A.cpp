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

#define N 100005
#define MOD 1000000007

using namespace std;

int n;
int a[N];

ll f( ll t , ll r )
{
	return (t+1)*(2*t+2*r+1);	
}
int main()
{
	int tc;
	cin >> tc;
	for( int i = 0 ; i < tc; ++i )
	{
		ll r , t;
		cin >> r >> t;
		ll lo = 0 , hi = 1LL<<20;
		if( !(f(lo,r) <= t) )
		{
			cout << "Case #" << i + 1 << ": " << 0 << endl;
			continue;	
		}
		double x = 2 , y = 2.0*r + 3  , z = 2.0*r + 1.0 - t;
		double disc = y*y - 4*x*z;
		double x0 = -y + sqrt( abs(disc) );
		x0 /= (2*x) ;
		ll sol ;
		for( ll k = max(0LL , (ll)(x0) - 100) ; k <= (ll)(x0) + 100 ; ++k )
			if( f(k,r) <= t )sol = k;
		cout << "Case #" << i + 1 << ": " << sol + 1 << endl;
	}
}
