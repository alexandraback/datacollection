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

typedef long long Lint;
typedef double db;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int maxn = 200020;
const int maxx = 10000;
const int MOd = 1e9+7;
const int K = 750;

int k, c, s;
Lint us[120];

Lint f( int n, int s ) {
	if( n > k ) n = k;
	if( s == 1 ) return n;
	return 1ll * (n-1) * us[s-1] + f( n+1, s-1 );
}

void solve() {
	scanf("%d %d %d",&k,&c,&s);
	if( k > c * s ) {
		printf("IMPOSSIBLE\n");
		return;
	}
	us[0] = 1;
	for(int i=1;i<=c;i++)
		us[i] = k * us[i-1];
	
	for(int i=1;i<=k;i+=c) {
		printf("%lld ",f( i, c ));
	}
	printf("\n");
}

int main() {
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		printf("Case #%d: ",i);
		solve();
	}
	
	return 0;
}
