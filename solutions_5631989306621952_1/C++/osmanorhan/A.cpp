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
char ar[maxn], bs[maxn];
int b, s;

void solve( ) {
	scanf(" %s",ar+1);
	a = strlen( ar+1 );
	b = s = a; bs[b] = ar[1];
	for(int i=2;i<=a;i++) {
		if( ar[i] >= bs[b] ) bs[--b] = ar[i];
		else bs[++s] = ar[i];
	}
	for(int i=b;i<=s;i++) printf("%c",bs[i]); printf("\n");
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
