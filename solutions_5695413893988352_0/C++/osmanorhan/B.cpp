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
typedef pair<Lint,ii> iii;

const int maxn = 200020;
const int maxx = 200000;
const int MOd = 1e9+7;

int a;
char ar[maxn], bs[maxn];
Lint mini, T[20];
Lint fir, sec;

void dfs( int n, Lint ar2, Lint bs2, Lint s ) {
	if( n == a+1 ) {
		//~ printf("how %d %d %d\n",ar2,bs2,s);
		if( abs(s) < mini || (abs(s) == mini && bs2 < sec) ) {
			mini = abs(s);
			fir = ar2;
			sec = bs2;
		} 
		return;
	}
	Lint b = T[a-n];
	if( ar[n] != '?' && bs[n] != '?' ) { dfs( n+1, ar2+(ar[n]-'0')*b, bs2+(bs[n]-'0')*b, s ); return; }
	
	vector<iii> v;
	if( ar[n] == '?' && bs[n] == '?' ) {
		for(int i=0;i<=9;i++) v.pb( iii( s-b*i, ii( 0, i ) ) );
		for(int i=1;i<=9;i++) v.pb( iii( s+b*i, ii( i, 0 ) ) );
	} else if( ar[n] == '?' ) {
		int h = bs[n]-'0';
		for(int i=0;i<=9;i++) v.pb( iii( s+b*(i-h), ii( i, h ) ) );
	} else if( bs[n] == '?' ) {
		int h = ar[n]-'0';
		for(int i=0;i<=9;i++) v.pb( iii( s+b*(h-i), ii( h, i ) ) );
	}
	sort( all( v ) );
	for(int i=0;i<v.size();i++) {
		if( i+1 >= v.size() || ( v[i+1].fi > 0 ) ) {
			dfs( n+1, ar2+v[i].se.fi*b, bs2+v[i].se.se*b, v[i].fi );
			//~ if( mini == 0 ) return;
			if( i+1 < v.size() )
				dfs( n+1, ar2+v[i+1].se.fi*b, bs2+v[i+1].se.se*b, v[i+1].fi );
			break;
		}
	}
	
}

void solve() {
	//~ scanf("%d",&a);
	
	scanf(" %s",ar+1);
	scanf(" %s",bs+1);
	a = strlen( ar+1 );
	//~ printf("asd %d\n",a);
	//~ reverse( ar+1, ar+1+a );
	//~ reverse( bs+1, bs+1+a );
	mini = 2e18;
	Lint t = 1, s = 0;
	for(int i=a;i>0;i--) {
		if( ar[i] != '?' && bs[i] != '?' ) s += (ar[i]-bs[i]) * t;
		t *= 10;
	}
	dfs( 1, 0, 0, s );
	//~ printf("asd %d %d %d\n",mini,fir,sec);
	for(int i=1;i<=a;i++) printf("%d",fir/T[a-i]), fir %= T[a-i]; printf(" ");
	for(int i=1;i<=a;i++) printf("%d",sec/T[a-i]), sec %= T[a-i]; printf("\n");
}

int main() {
	
	int n;
	scanf("%d",&n);
	T[0] = 1;
	for(int i=1;i<=18;i++)
		T[i] = T[i-1] * 10;
	
	int cnt = 0;
	while( n-- ) {
		printf("Case #%d: ",++cnt);
		solve();
	}
	
	return 0;
}
