#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 20;
const int offset = 1000;
struct P{
	int d, w, e, s;
};

bool cmp(const P& a, const P& b) {
	return a.d < b.d;
}

int h[2000];

int main() {
	int T;
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("w.txt", "w", stdout); 
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int N;
		scanf("%d", &N);
		vector<P> v;
		memset(h, 0, sizeof(h));
		for (int i = 0; i < N; i++) {
			int d, n, w, e, s, delta_d, delta_p, delta_s;
			// printf("%d\n", i);
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			for (int j = 0; j < n; j++) {
				P u;
				u.d = d + delta_d * j;
				u.w = w + delta_p * j + offset;
				u.e = e + delta_p * j + offset;
				u.s = s + delta_s * j;
				//printf("w = %d, e = %d\n", u.w, u.e);
				v.push_back(u);
			}
		}
		sort(v.begin(), v.end(), cmp);
		int l = 0, ans = 0;
		while (l < v.size()) {
			vector<P> a;
			a.push_back(v[l]);
			l++;
			while (l < v.size() && v[l].d == a[0].d) {
				a.push_back(v[l]);
				l++;
			}
			
			for (int i = 0; i < a.size(); i++) {
				for (int j = a[i].w; j < a[i].e; j++) {
					if (a[i].s > h[j]) {
						ans++;
						break;
					}
				}
			}
			for (int i = 0; i < a.size(); i++) {
				for (int j = a[i].w; j < a[i].e; j++) {
					if (a[i].s > h[j]) {
						h[j] = a[i].s;
					}
				}
			}
			
		}
		printf("Case #%d: %d\n", re, ans);
	}
}
