#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m;
int graph[ 55 ][ 55 ];
string zip[ 55 ];
string answer;
vector< int > order;

void rec( int pos, vector< int > mem, string result )
{
	if ( pos == order.size() )
	{
		answer = min( answer, result );
		return;
	}
	while ( true )
	{
		vector< int > cur = mem;
		if ( graph[ cur.back() ][ order[ pos ] ] )
		{
			cur.push_back( order[ pos ] );
			rec( pos + 1, cur, result + zip[ order[ pos ] ] );
		}
		if ( mem.size() == 1 ) return;
		mem.pop_back();
	}
}

void solve()
{
	memset( graph, 0, sizeof( graph ) );
	cin >> n >> m;
	answer = "";
	for ( int i = 0; i < n; i++ ) cin >> zip[i], answer += "99999";
	for ( int i = 1; i <= m; i++ )
	{
		int a, b; cin >> a >> b;
		a--; b--;
		graph[a][b] = graph[b][a] = 1;
	}
	order.clear();
	for ( int i = 0; i < n; i++ ) order.push_back( i );
	do
	{
		vector< int > start;
		start.push_back( order[ 0 ] );
		rec( 1, start, zip[ order[ 0 ] ] );
	} while ( next_permutation( order.begin(), order.end() ) );
	cout << answer << "\n";
}

int main (int argc, const char * argv[])
{
	int testcases; cin >> testcases;
	for ( int i = 1; i <= testcases; i++ )
	{
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}