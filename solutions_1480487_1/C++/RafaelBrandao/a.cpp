#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int cn, cases;
int n;
double sum=0;
int scores[220], s[220];

int main() {
	scanf("%d",&cases);
	while (cn++ < cases) {
		scanf("%d",&n);
		int t;
		sum = 0;
		for (int i=0; i < n; ++i) {
			scanf("%d",&scores[i]);
			sum += scores[i];
		}
		//printf("sum = %.2lf",sum);
		printf("Case #%d:",cn);
		for (int i=0; i < n; ++i) {
			memcpy(s, scores, sizeof(scores));
			s[i] = -1;
			sort(s, s+n);
			//for (int j=0; j < n; ++j) printf(" %d",scores[j]); printf("\n");
			//for (int j=0; j < n; ++j) printf(" %d",s[j]); printf("\n");
			double lo = 0.0, hi = 1.0, mid, ok = 1.0;
			double prox, at, k, left;
			int it = 80;
			while (it--) {
				mid = (lo+hi)/2.0;
				at = (scores[i]+(sum*mid));
				//printf("trying %d with score %.2lf and %.2lf percent: %.2lf", i, (double)scores[i], mid, at);
				left = 0.0, k = 0.0;
				for (int i=1; i < n; ++i) {
					if (s[i] > at) break;
					k = (double)(at - (double)s[i]) / sum;
					left += k;
				}
				//printf("left: %.2lf\n",left);
				if (left > (1.0-mid)) {
					ok = mid;
					hi = mid;
				} else lo = mid;
			}
			printf(" %.6lf", ok*100.0);
		}
		printf("\n");
		
	}

	return 0;
}
