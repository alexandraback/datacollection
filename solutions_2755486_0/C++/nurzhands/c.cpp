#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define ms(a,x) memset(a,x,sizeof a)
#define ones(x) __builtin_popcount(x)
#define rep(i,n) for (int i = 0; i < n; i++)
#define forit(i,a) for (typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 500;
const int add = N/2;

int h[N];

struct st {
	int d,w,e,s;
	st(int _d, int _w, int _e, int _s) {
		d=_d; w=_w; e=_e; s=_s;
	}
};

vector<st> a;

bool cmp(const st &a, const st &b) {
	return a.d < b.d;
}

int main()
{
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	int tests;
	scanf("%d\n", &tests);

	for (int test = 1; test <= tests; test++) {
		int N;
		scanf("%d",&N);
		a.clear();
		for (int k = 0; k < N; k++) {
			int d,n,w,e,s,xd,xp,xs;
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&xd,&xp,&xs);
			for (int i = 0; i < n; i++)
				a.pb(st(d+xd*i,w+xp*i,e+xp*i,s+xs*i));
		}
		ms(h,0);
		sort(all(a),cmp);
		int last = 0;
		int ans = 0;
		for (int k = 0; k < sz(a); k++) {
			//printf(":%d %d %d %d\n", a[k].d, a[k].w, a[k].e, a[k].s);
			if (k && a[k].d > a[k-1].d) {
				for (int l = last; l < k; l++) {
					int w = a[l].w;
					int e = a[l].e;
					int s = a[l].s;
					for (int i = w; i < e; i++)
						h[i+add] = max(h[i+add], s);
				}
				last = k;
			}
			/*printf(":");
			for (int i = 0; i < 10; i++)
				printf("%d ", h[i+add]);
			printf("\n");*/
			int w = a[k].w;
			int e = a[k].e;
			int s = a[k].s;
			bool ok = 0;
			for (int i = w; i < e; i++)
				if (h[i+add] < s) {
					ok = 1;
					break;
				}
			ans += ok;
		}
		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}
