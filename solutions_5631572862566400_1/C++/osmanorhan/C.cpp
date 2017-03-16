#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
#include <vector>
#define all(x) x.begin() , x.end()
#define fi first
#define se second
#define pb push_back
#define umax( x , y ) x = max( x , (y) )
#define umin( x , y ) x = min( x , (y) )
#define For( i , a ) for(int i=1;i<=a;i++)
#define ort (b+s)/2
#define y2 asrwjaelkf
#define pa() printf("asdasd\n");
#define y1 asseopirwjaelkf

using namespace std;

const int maxn = 2020;
const int maxx = 10000;
const int MOd = 1e9+7;
const int K = 750;

typedef long long Lint;
typedef double db;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int a;
int next[maxn];
int used[maxn];
vector<int> w[maxn];
vector<int> c[maxn];
int st[maxn], at;
int b, s, cyc[maxn];
int ans = 0;

void dfss( int n ) {
	if( used[n] ) {
		if( used[n] == 2 ) return;
		cyc[n] = ++s;
		c[s].pb( n );
		//~ printf("asd\n");
		while( at > 0 && st[at] != n ) {
			//~ printf("---------- %d %d(%d)\n",s,st[at],n);
			c[s].pb( st[at] );
			cyc[st[at]] = s;
			at--;
		}
		
		return;
	}
	used[n] = 1;
	st[++at] = n;
	dfss( next[n] );
	at--;
	//~ printf("fin %d\n",n);
	used[n] = 2;
}

int dfs( int n, int back ) {
	int ret = 0;
	for(int i=0;i<w[n].size();i++)
		if( !cyc[w[n][i]] && w[n][i] != back ) {
			int t = dfs( w[n][i], n ) + 1;
			//~ if( n == 3 ) printf("asd %d %d\n",w[n][i],t);
			//~ umax( ans, ret+t+1 );
			umax( ret, t );
		}
	return ret;
}

void solve( ) {
	ans = 0;
	memset( next, 0, sizeof( next ) );
	memset( cyc, 0, sizeof( cyc ) );
	memset( used, 0, sizeof( used ) );
	for(int i=1;i<=a;i++) c[i].clear(), w[i].clear();
	
	scanf("%d",&a);
	
	for(int i=1;i<=a;i++) {
		scanf("%d",&next[i]);
		w[i].pb( next[i] );
		w[next[i]].pb( i );
	}
	s = 0;
	for(int i=1;i<=a;i++)
		if( !used[i] ) {
			//~ printf("asd %d\n",i);
			at = 0;
			dfss( i );
		}
	
	memset( used, 0, sizeof( used ) );
	int H = 0;
	for(int i=1;i<=a;i++)
		if( cyc[i] && !used[i] ) {
			int h = cyc[i];
			umax( ans, (int)c[h].size() );
			//~ printf("asd %d %d %d\n",i,cyc[i],c[h].size());
			vector<int> v;
			for(int j=0;j<c[h].size();j++) {
				v.pb( dfs( c[h][j], 0 ) );
				used[c[h][j]] = 1;
				//~ printf("--- %d %d %d\n",c[h][j],v[j],ans);
			}
			if( v.size() == 2 ) H += v[0]+v[1]+2;
		}
	umax( ans, H );
	cout << ans << endl;
	//~ cout << H << endl;
}

int main() {
	
	//~ freopen("asd2.in","r",stdin);
	//~ freopen("asd.out","w",stdout);
	
	int n, cnt = 0;
	scanf("%d",&n);
	
	while( n-- ) {
		printf("Case #%d: ",++cnt);
		solve();
	}
	
	return 0;
}
