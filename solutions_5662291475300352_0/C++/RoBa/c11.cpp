#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 110;
struct P {int start, inv;} p[MAXN];
int d[MAXN], h[MAXN], m[MAXN];
int np;

int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		int n;
		scanf("%d",&n);
		np = 0;
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d%d%d",&d[i],&h[i],&m[i]);
			for (int j = 0 ; j < h[i] ; ++j) {
				p[np].start = d[i];
				p[np].inv = m[i] + j;
				++np;
			}

		}
		printf("Case #%d: ", ca);
		if (np < 2) {
			printf("0\n");
			continue;
		}
		if (np == 2) {
			if (p[0].inv == p[1].inv) {
				printf("0\n");
				continue;
			}
			if (p[0].inv < p[1].inv) swap(p[0], p[1]);
			double v1, v2, s1, s2, t1, t2, dis1, dis2;
			v1 = 360.0 / p[0].inv;
			v2 = 360.0 / p[1].inv;
			s1 = p[0].start;
			s2 = p[1].start;
			if (s1 < s2) {
				t1 = (s2 - s1 - 360) / (v1 - v2);
				t2 = (s2 - s1 - 720) / (v1 - v2);
			} else {
				t1 = (s2 - s1) / (v1 - v2);
				t2 = (s2 - s1 - 360) / (v1 - v2);
			}
			dis1 = s1 + t1 * v1;
			dis2 = s1 + t2 * v1;
			// printf("dis1:%f dis2:%f\n", dis1, dis2);
			// printf("t1:%f t2:%f dis:%f", t1, t2, v1*(t2-t1));
			/*if (v1 * (t2 - t1) <= 360) {
				printf("1\n");
			} else {
				printf("0\n");
			}*/
			if (dis2 <= 360) {
				printf("1\n");
			} else {
				printf("0\n");
			}
			continue;
		}
		printf("-1\n");
	}
	return 0;
}