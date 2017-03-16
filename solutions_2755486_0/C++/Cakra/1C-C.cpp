#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
	string c;
	while(x) { c.PB(x%2+'0'); x /= 2; }
	while(sz(c) < len) c.PB('0');
	reverse(all(c));
	return c;
}
//------------------------------

int T, N;
map<int, int> h;

struct data {
	int d, w, e, s;
	bool operator < (const data &ot) const {
		return d < ot.d;
	}
} ar[105];

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		scanf("%d", &N);
		
		int na = 0;
		for(int i = 0; i < N; i++) {
			int d, n, w, e, s, dd, dp, ds;
			scanf("%d %d %d%d %d %d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			
			for(int j = 0; j < n; j++) {
				ar[na++] = (data) {d, w, e, s};
				d += dd;
				w += dp; e += dp;
				s += ds;
			}
		}
		
		sort(ar, ar + na);
		
		h.clear();
		
		int ans = 0, ma = -1;
		for(int i = 0; i < na; i++) {
			int d = ar[i].d, w = ar[i].w, e = ar[i].e, s = ar[i].s;
			
//			printf("i=%d, d=%d, (%d, %d)=%d\n", i, d, w, e, s);
			
			for(int k = 2*w; k <= 2*e; k++)
				if(h[k] < s) {
//					printf("^succeed\n");
					ans++;
					break;
				}
			
			ma = max(ma, s);
			
			if(i+1 < na) {
				if(d != ar[i+1].d) {
					// perbaiki sekarang
					for(int j = i; j >= 0 && ar[j].d == ar[i].d; j--)
						for(int k = 2*ar[j].w; k <= 2*ar[j].e; k++)
							h[k] = max(h[k], ma);
					
					ma = -1;
				}
			}
		}
		
		printf("Case #%d: %d\n", tc+1, ans);
	}
	
	return 0;
}
