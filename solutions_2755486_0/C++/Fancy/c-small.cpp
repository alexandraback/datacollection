#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 15;

struct att {
	int d, w, e, s;
	att(int d, int w, int e, int s):d(d),w(w),e(e),s(s){}
	bool operator<(const att& rhs) const {
		return d < rhs.d;
	}
};

int N, d[MAXN], n[MAXN], w[MAXN], e[MAXN];
int s[MAXN], dd[MAXN], dp[MAXN], ds[MAXN];

int gao() {
	scanf("%d", &N);
	vector<att> v;
	map<int,int> h, nh;
	for(int i=0; i<N; ++i) {
		int d, n, w, e, s, dd, dp, ds;
		scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
		for(int j=0; j<n; ++j, d+=dd, w+=dp, e+=dp, s+=ds) {
			v.push_back(att(d, w, e, s));
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i=0; i<v.size(); ++i) {
		int d = v[i].d;
		int w = v[i].w;
		int e = v[i].e;
		int s = v[i].s;
		bool flag = false;
		for(int j=w; j<e; ++j) {
			if(h[j] < s) {
				flag = true;
				nh[j] = max(nh[j], s);
			}
		}
		if(flag) ++ans;//printf("%d %d %d %d\n", d, w, e, s);
		// raise wall
		if(i+1==v.size() || d != v[i+1].d) {
			for(map<int,int>::iterator it=nh.begin(); it!=nh.end(); ++it) {
				h[it->first] = it->second;
			}
			nh.clear();
		}
	}
	return ans;
}

int main() {
	int T; scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		printf("Case #%d: %d\n", cas, gao());
	}
}
