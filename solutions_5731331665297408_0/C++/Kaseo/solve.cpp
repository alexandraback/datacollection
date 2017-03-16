#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

//const int INF = 5003;
const long long INF = 1000000007;
const int MAXN = 100005;
typedef pair <int, int> ii;
//typedef pair <long long, long long> ii;
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}

bool v[55];
long long d[55];
map <long long, int> mp;
long long id[55];
vector <ii> e[55];
ii re[55];

long long getdist( int x ){
	v[x] = 1;
	int si = e[x].size();

	long long t = 0;
	for(int i=0; i<si; i++)
		if( !v[e[x][i].second] )
			t = t + getdist( e[x][i].second ) + 2;
	return t;
}

void go( int x ){
	printf("%05d", id[x]);
	v[x] = 1;
	int si = e[x].size();

	for(int i=0; i<si; i++)
		if( !v[e[x][i].second] )
			go( e[x][i].second );
}

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		
		mp.clear();
		for(int i=0; i<55; i++)
			e[i].clear();
		memset( v, 0, sizeof( v ) );
		
		int n, m;
		scanf("%d %d", &n, &m);

		
		for(int i=1; i<=n; i++){
			scanf("%lld", id+i);
			mp[id[i]] = i;
			
		}

		for(int i=0; i<m; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			e[x].push_back( ii(id[y], y) );
			e[y].push_back( ii(id[x], x) );
		}

		for(int i=1; i<=n; i++)
			sort( e[i].begin(), e[i].end() );

		long long dd = INF;
		for(int i=1; i<=n; i++){
			memset( v, 0, sizeof( v ) );
			d[i] = getdist( i );
			dd = min( dd, d[i] );

		}

		int p = INF;
		int x = -1;
		for(int i=1; i<=n; i++){
			if( dd == d[i] && id[i] < p ){
				p = id[i];
				x = i;
			}
		}

		printf("Case #%d: ", R);
		memset( v, 0, sizeof( v ) );
		go( x );
		puts("");
	}
	
}