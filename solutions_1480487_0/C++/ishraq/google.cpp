#include <cstdio>
#include <algorithm>
#define MAX_N 300

using namespace std;

int scores[MAX_N];
int x;
int n;

int main() {
	int T;
	scanf("%d", &T);
	for (int rayge = 1; rayge <= T; rayge++) {
		scanf("%d\n", &n);
		x = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &scores[i]);
			x += scores[i];
		}
		double tot_of_scores = 2.0 * x;
		int num_over = 0;
		double needed = (tot_of_scores) / (n-num_over);
		//for (int i = 0; i < 210; i++) {
			for (int i = 0; i < n; i++) {
				if (scores[i] > needed) {
					num_over++;
					tot_of_scores -= scores[i];
				}
			}
			needed = (tot_of_scores) / (n-num_over);
		//}
		printf("Case #%d:", rayge);
		for (int i = 0; i < n; i++) {
			double m = (needed - scores[i]) / x; //m = (needed - scores[i]) / x
			printf(" %.6lf", max(m * 100, 0.0));
		}
		printf("\n");
	}
}
