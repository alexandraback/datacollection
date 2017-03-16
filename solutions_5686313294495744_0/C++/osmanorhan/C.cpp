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

const int maxn = 1020;
const int maxx = 200000;
const int MOd = 1e9+7;

int a;
string s[maxn], s2[maxn];
map<string,int> mp, mp2;
ii ar[maxn];
bool used[maxn], used2[maxn];

void solve() {
	
	scanf("%d",&a);
	mp.clear();
	mp2.clear();
	for(int i=1;i<=a;i++) {
		cin >> s[i] >> s2[i];
		mp[s[i]] = mp2[s2[i]] = 1;
	}
	int cnt = 0, cnt2 = 0;
	for( map<string,int> :: iterator it = mp.begin() ; it != mp.end() ; it++ ) it->se = ++cnt;
	for( map<string,int> :: iterator it = mp2.begin() ; it != mp2.end() ; it++ ) it->se = ++cnt2;
	
	for(int i=1;i<=a;i++) {
		ar[i].fi = mp[s[i]];
		ar[i].se = mp2[s2[i]];
	}
	int ans = 0;
	for(int i=1;i<(1<<a);i++) {
		for(int j=1;j<=cnt;j++) used[j] = 0;
		for(int j=1;j<=cnt2;j++) used2[j] = 0;
		for(int j=0;j<a;j++)
			if( i&(1<<j) ) used[ar[j+1].fi] = used2[ar[j+1].se] = 1;
		int c = 1;
		for(int j=1;j<=cnt;j++) c &= used[j];
		for(int j=1;j<=cnt2;j++) c &= used2[j];
		if( c ) {
			int t = a;
			for(int j=0;j<a;j++)
				if( (1<<j)&i ) t--;
			umax( ans, t );
		}
	}
	cout << ans << endl;
}

int main() {
	
	int n;
	scanf("%d",&n);
	int cnt = 0;
	while( n-- ) {
		printf("Case #%d: ",++cnt);
		solve();
	}
	
	return 0;
}
