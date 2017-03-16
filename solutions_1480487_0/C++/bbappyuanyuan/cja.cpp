#include <cstdio>

const int maxn = 200 + 10;
const double epsi = 1e-10;

int n;
double X;
int s[maxn];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs) {
		scanf("%d", &n);
		X = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
			X += s[i];
		}
		
		printf("Case #%d:", cs);
		for (int k = 0; k < n; ++k) {
			//printf("k = %d\n", k);
			double l = 0.0, r = 1.0 + epsi, mid, res, sm, score;
			while (r - l > epsi) {
				mid = (l + r) * 0.5;
				sm = mid;
				score = s[k] + sm * X;
				for (int i = 0; i < n; ++i)
					if (i != k && score > s[i] + epsi)
						sm += (score - s[i]) / X;
				//printf("%.2lf %.2lf\n", mid, sm);
				if (sm >= 1.0)
					r = res = mid;
				else
					l = mid;
			}
			printf(" %.10lf", res * 100);
		}
		printf("\n");
	}
	
	return 0;
}
