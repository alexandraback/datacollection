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

int r , n , m , k;
int v[N];
int T[N];
int cnt[11];
int solve ;
int ans;
vector < pair <int, int> > primeFact( int num )
{
	vector < pair <int, int> > V;
	
	for( int i = 2 ; i*i <= num ; i++ )
	{
		int a=0;
		while(num%i==0)
		{
			num/=i;
			a++;
		}
		if( a != 0 ) V.push_back( make_pair(i, a) );
	}
	if( num > 1 ) V.push_back( make_pair(num, 1) );
	
	return V;
}
bool f( int x )
{
	while( x > 0 )
	{
		if( x%10 == 4 )cnt[2]+=2;
		else if( x%10 == 6 )cnt[2]++ , cnt[3]++;
		else if( x%10 == 8 )cnt[2]+=3;
		else	cnt[x%10]++;
		if( x%10 <= 1 )return 1;
		if( x%10 > m ) return 1;
		x/= 10;	
	}	
	return 0;
}
void doit()
{
	for( int u = (int)(pow(10.0 , n - 1) + eps) ; u < (int)(pow(10.0 , n) + eps) ; ++u )
	{
		solve = 0;		
		me( cnt , 0 );
		if( f(u) )continue;
		//cout << u << endl;
		for( int i = 0 ; i < k ; ++i )
		{
			vector < pair <int, int> > fp = primeFact( v[i] );
			bool ok = 1;
			for( int j = 0 ; ok && ( j < fp.size() ); ++j )
				if( fp[j].first > m || fp[j].second > cnt[fp[j].first]  ) ok = 0;
			if( ok )solve ++ , ans = u;
		}
		if( solve == k )break;
	}
	cout << ans << endl;
}
int main()
{
	int tc;
	cin >> tc;
	cin >> r >> n >> m >> k;
	puts("Case #1:");
	for( int i = 0 ; i < r ; ++i )
	{
		for( int j = 0 ; j < k ; ++j )cin >> v[j];
		doit();
	}
}
