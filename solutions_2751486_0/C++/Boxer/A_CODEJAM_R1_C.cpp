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
#define pii pair< int , int >
#define pll pair< ll , ll >
#define mp make_pair
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define me(t,val) memset( t , val , sizeof(t) )
#define ones(x) __builtin_popcount(x)
#define test puts("test");
#define sync ios_base::sync_with_stdio(false);

#define N 100005
#define MOD 1000000007
#define INF (1<<30)
#define EPS (1e-5)

using namespace std;

string s;
ll n , ns ;
int t;

void doit()
{
	vi v;
	int cnt = 0;
	for( int i = 0 ; i < ns ; ++i )
	{
		if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
			s[i] = '0' , cnt = 0;
		else	s[i] = '1' , cnt++;
		if( cnt >= n )v.pb( i );
	}
	ll ans = 0;	
	if( v.empty() )
	{
		cout << "Case #"<< t + 1 << ": " << ans << endl;
		return;	
	}
	
	for( int i = 0 ; i + n - 1 < ns ; ++i )
	{
		if( i + n - 1 > v.back() )break;
		int Ind = lower_bound( all(v) , i + n - 1 ) - v.begin();
		ans += ns - v[Ind];
	}

	cout << "Case #"<< t + 1 << ": " << ans << endl;
}

int main()
{
	sync
	int tc;
	cin >> tc;
	for( t = 0 ; t < tc ; ++t )
	{
		cin >> s >> n ;
		ns = s.size();
		doit();
	}
}
