#include <cstdio>
#include <vector>
#include <cmath>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
#define EPS 1e-9
#define MAXN 200
int TC, N;
int A[MAXN+10];
vector<ii> V;

int main(int argc, char *argv[])
{
	int tot, gt;
	double lo, hi, mid, sc, tmp, rem;
	scanf("%d", &TC);
	for (int t = 1; t <= TC; t++) {
		scanf("%d", &N);
		tot = 0;
		V.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			tot += A[i];
			V.push_back(ii(A[i], i));
		}
		lo = 0.0, hi = 100.0;
		printf("Case #%d:", t);
		for (int i = 0; i < N; i++) {
			lo = 0.0, hi = 100.0;
			while (fabs(lo-hi) > EPS) {
				mid = (lo+hi)/2;
				sc = (double) A[i] + mid * (double)tot / 100.0;
				rem = 100 - mid;
				gt = 0;
				for (int k = 0; k < N; k++) {
					if (i != k) {
						if (A[k] - sc > EPS) {
							gt++;
						} else {
							tmp = (sc + 1e-6 - (double)A[k]) * 100.0 / (double)tot;
							// same score
							if (rem - tmp > EPS) {
								rem -= tmp;
								gt++;
							}
						}
					}
				}
				if (gt <= N-2)
					hi = mid;
				else
					lo = mid+1e-6;
			}
			printf(" %.6lf", mid);
		}
		putchar('\n');
	}
	return 0;
}
