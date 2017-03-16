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

int a, b, last, H[maxn][40];
int ar[40];
int at;
vector<Lint> w[maxn];

Lint f( int n ) {
	Lint t = 1, s = 0;
	for(int i=0;i<=last;i++) {
		if( ar[i] ) s += t;
		t *= n;
	}
	//~ for(int i=0;i<a;i++) printf("%d",ar[a-i-1]);
	//~ printf(" asd %d -- %d\n",s,n);
	Lint h = 1;
		for(int j=1;j<a;j++) {
			h *= n;
			//~ h %= i;
		}
	//~ cout << h << endl;
	for(Lint i=2;i*i<s;i++) {
		Lint h = 1;
		for(int j=1;j<a;j++) {
			h *= n;
			h %= i;
		}
		//~ printf("asd %d -- %d %d\n",i,h,s);
		if( (h+s) % i == 0 ) return i;
	}
	return 0;
}

void solve() {
	vector<Lint> v;
	for(int i=2;i<=10;i++) {
		int h = f( i );
		if( !h ) return;
		else v.pb( h );
	}
	w[++at] = v;
	for(int i=0;i<a;i++)
		H[at][i] = ar[i];
	//~ printf("  ----- %d %d\n",at,last);
}

int main() {
	int n = 1;
	printf("Case #1:\n");
	scanf("%d %d %d",&n,&a,&b);
	//~ printf("asdasd\n");
	ar[0] = ar[a-1] = 1;
	
	while( !ar[a] && at < b ) {
		
		solve();
		//~ if(  )
		ar[1]++;
		for(int i=1;i<a;i++)
			if( ar[i] > 1 ) ar[i+1] += ar[i]/2, ar[i] %= 2, umax( last, i+1 );
	}
	for(int i=1;i<=at;i++) {
		for(int j=0;j<a;j++) printf("%d",H[i][a-j-1]); printf(" ");
		for(int j=0;j<w[i].size();j++) printf("%lld ",w[i][j]);
		printf("\n");
	}
	
	return 0;
}
