#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

ll vis[10000005];

void get() {
	memset(vis,-1,sizeof(vis));
	vis[1] = 1;
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()) {
		int i = Q.front();
		Q.pop();
		
		int j = i+1;
		if(j < 10000000 && vis[j]==-1) {
			vis[j] = vis[i]+1;
			Q.push(j);
		}
		
		int rev = 0;
		j = i;
		while(j) {
			rev = rev*10+j%10;
			j /= 10;
		}
		j = rev;
		if(j < 10000000 && vis[j]==-1) {
			vis[j] = vis[i]+1;
			Q.push(j);
		}
	}
}

const int MAXL = 16;

ll n;

ll cnt[MAXL];

int d[MAXL];

int solve() {
	cnt[1] = 9;
	ll p = 9;
	for(int i = 2; i < MAXL; i++) {
		if(i%2) {
			p = 10*p+9;
			cnt[i] = p + p/10 + 1;
		} else {
			cnt[i] = p*2 + 1;
		}
	}
	ll m = n;
	ll tot = 0;
	int len = 0;
	p = 1;
	while(m) {
		tot += cnt[len];
		d[len++] = m%10;
		m /= 10;
		p *= 10;
	}
	p = p/10-1;
	ll ans = tot+n-p;
	if(d[0]) {
		for(int l = 1; l <= len; l++) {
			ll a = 0;
			for(int i = len-l; i < len; i++) {
				a = a*10 + d[i];
			}
			ll b = 0;
			for(int i = len-l-1; i >= 0; i--) {
				b = b*10 + d[i];
			}
			ans = min(ans, tot+a+b+1);
		}
	}
	return ans;
}

int main() {
	get();
	
//	for(n = 1; n <= 30; n++) {
//		if(solve() != vis[n]) {
//			cout << n << " : " << solve() << " " << vis[n] << endl;
//			return 0;
//		}
//	}
//	return 0;

	freopen("A-input.in", "r", stdin);
	freopen("A-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", c, vis[n]);
	}
}
