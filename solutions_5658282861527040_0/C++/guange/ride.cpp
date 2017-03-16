#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <stack>

using namespace std;
#define ll long long 
#define eps 1e-8
#define inf 0x3f3f3f3f
#define N 100005
#define M 202000
#define mod 1000000007
#define MP make_pair

int main()
{
	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );
	int T, ans, n, m, k, cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d%d", &n, &m, &k );
		ans = 0;
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j ) if( (i&j) < k ) ++ans;
		printf( "Case #%d: %d\n", ++cas, ans );
	}
}