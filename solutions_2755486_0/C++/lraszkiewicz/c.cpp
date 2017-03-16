#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int N;
		scanf("%d", &N);
		std::vector<std::vector<int> > a;
		for(int j = 0; j < N; j++) {
			int d, n, w, e, s, delta_d, delta_p, delta_s;
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			for(int k = 0; k < n; k++) {
				std::vector<int> ta;
				ta.push_back(d + k * delta_d);
				ta.push_back(s + k * delta_s);
				ta.push_back((w + k * delta_p) * 2);
				ta.push_back((e + k * delta_p) * 2);
				a.push_back(ta);
			}
		}
		int h[2000];
		std::fill(h, h + 2000, 0);
		std::sort(a.begin(), a.end());
		int res = 0;
		for(int j = 0; j < a.size(); j++) {
			//printf("%d %d %d %d ", a[j][0], a[j][1], a[j][2], a[j][3]);
			for(int k = a[j][2]; k <= a[j][3]; k++)
				if(h[k * 2 + 1000] < a[j][1]) {
					res++;
					break;
				}
			//printf(" %d\n", res);
			for(int k = a[j][2]; k <= a[j][3]; k++)
				if(h[k * 2 + 1000] < a[j][1])
					h[k * 2 + 1000] = a[j][1];
		}
		printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}
