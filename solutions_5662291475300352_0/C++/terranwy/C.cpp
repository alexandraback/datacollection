#include <cstdio>

int casei, cases, n, hi, ans, d, h, m;
int hiker[10][2];

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		hi = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &d, &h, &m);
			for (int j = 0; j < h; ++j) {
				hiker[hi][0] = d;
				hiker[hi][1] = m + j;
				++hi;
			}
		}
		
		if (hi == 1 || hiker[0][1] == hiker[1][1]) {
			ans = 0;
		}
		else {
			if (hiker[0][1] < hiker[1][1]) {
				int t = hiker[0][0];
				hiker[0][0] = hiker[1][0];
				hiker[1][0] = t;
				t = hiker[0][1];
				hiker[0][1] = hiker[1][1];
				hiker[1][1] = t;
			}
			
			//double t = (360 - hiker[0][0]) / 360.0 * hiker[0][1];
			//double p = hiker[1][0] + t / hiker[1][1] * 360;
			double p = hiker[1][0] + (360 - hiker[0][0]) * hiker[0][1] / hiker[1][1];
			if (p >= 720) ans = 1;
			else ans = 0;
		}
		
		printf("Case #%d: %d\n", casei, ans);
	}
	
	return 0;
}