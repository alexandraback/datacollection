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
#define y1 asseopirwjaelkf
#define hash ____hash
#define next ____next

using namespace std;

typedef long long Lint;
typedef long double db;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int maxn = 200020;
const int maxx = 200000;
const int MOd = 1e9+7;

int a;
char ar[maxn];
int s[200];
char bs[100][8] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

char tem[20] = {"ZOWTFVXSGN"};
int h[20];

void solve() {
	int a;
	scanf(" %s",ar+1);
	a = strlen( ar+1 );
	memset( s, 0, sizeof( s ) );
	for(int i=1;i<=a;i++) {
		s[ar[i]]++;
	}
	vector<int> v;
	for(int i=0;i<=9;i++) {
		int t = h[i+1];
		int k = tem[t];
		//~ printf("asd %d %c %d\n",t,k,s[k]);
		while( s[k] ) {
			v.pb( t );
			for(int j=0;bs[t][j];j++)
				s[bs[t][j]]--;
		}
	}
	for(int i='A';i<='Z';i++) if( s[i] != 0 ) assert(0);
	sort( all( v ) );
	for(int i=0;i<v.size();i++)
		printf("%d",v[i]); printf("\n");
	
}

int main() {
	
	h[1] = 0;
	h[2] = 2;
	h[3] = 6;
	h[4] = 7;
	h[5] = 8;
	h[6] = 5;
	h[7] = 4;
	h[8] = 3;
	h[9] = 1;
	h[10] = 9;
	
	int n;
	scanf("%d",&n);
	int cnt = 0;
	while( n-- ) {
		printf("Case #%d: ",++cnt);
		solve();
	}
	
	return 0;
}
