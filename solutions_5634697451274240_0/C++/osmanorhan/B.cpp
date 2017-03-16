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
char ar[maxn], bs[maxn];

void swapp( int n ) {
	for(int i=1;i<=n;i++) {
		if( ar[i] == '+' ) bs[n-i+1] = '-';
		if( ar[i] == '-' ) bs[n-i+1] = '+';
	}
	for(int i=1;i<=n;i++) ar[i] = bs[i];
}

void solve() {
	
	scanf(" %s",ar+1);
	a = strlen( ar+1 );
	int s = a;
	int ans = 0;
	while( 0 < s ) {
		while( s > 0 && ar[s] == '+' ) s--;
		if( s < 1 ) break;
		int i = 1;
		while( i < s && ar[i] == '+' ) i++;
		if( ar[i] == '-' && i > 1 )	swapp( i-1 ), ans++;
		ans++;
		swapp( s );
	}
	cout << ans << endl;
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
