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

int a;
bool used[20];

void solve() {
	scanf("%d",&a);
	if( a == 0 ) {
		printf("INSOMNIA\n");
		return;
	}
	memset( used, 0, sizeof( used ) );
	int t = a;
	while( 1 ) {
		int c = t;
		while( c ) {
			used[c%10] = 1;
			c /= 10;
		}
		int h = 0;
		for(int i=0;i<10;i++)
			if( !used[i] ) h = 1;
		if( !h ) {
			printf("%d\n",t);
			return;
		}
		t += a;
	}
	
}

int main() {
	
	int n = 1, cnt = 0;
	scanf("%d",&n);
	while( n-- ) {
		printf("Case #%d: ",++cnt);
		solve();
	}
	
	return 0;
}
