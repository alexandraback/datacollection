#include <cstdio>
using namespace std;

int n;
int x;
int score[242];

double will_win(int pos, double y) {
	y /= 100;
	double r = score[pos] + x*y;
	double need = 0;
	for (int i = 0; i < n; ++i) {
		if (i == pos) continue;
		double needs = (r-score[i])/x;
		if (needs < 0) needs = 0;
		need += needs;
		if (need > 1-y) return true;
	}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		printf("Case #%d:", tt);
		scanf("%d", &n);
		x = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &score[i]);
			x += score[i];
		}
		for (int j = 0; j < n; ++j) {
			double min = 0;
			double max = 100;
			for (int i = 0; i < 100; ++i) {
				double c = min+(max-min)/2;
				if (will_win(j, c)) max = c;
				else min = c;
			}
			printf(" %.9lf", min);
		}
		printf("\n");
	}
}
