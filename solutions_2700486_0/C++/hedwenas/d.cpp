#include<stdio.h>
#include<string.h>
#include<algorithm>

int t;
int bias = 100;
int M[2];
int n, x, y;
double ans;

void sim2 (int height, int nec, int trials, double prob) {
	if (trials == 0) {
		if (M[1] >= nec)
			ans += prob;
		return ;
	}

	if (M[0] < height and M[1] < height) {
		M[0] ++;
		sim2 (height, nec, trials-1, prob * 0.5f);
		M[0] -= 1;
		M[1] ++;
		sim2 (height, nec, trials-1, prob * 0.5f);
		M[1] -= 1;
	} else if (M[0] < height) {
		M[0] ++;
		sim2 (height, nec, trials-1, prob);
		M[0] -= 1;
	} else {
		M[1] ++;
		sim2 (height, nec, trials-1, prob);
		M[1] -= 1;
	}
}

void sim (int height, int nec, int trials) {
	sim2 (height, nec, trials, 1.0f);
}

int main() {
	scanf ("%d", &t);
	int caze = 0;
	while (t --) {
		caze ++;
		memset (M, 0, sizeof M);
		ans = 0;
		
		scanf ("%d%d%d", &n, &x, &y);
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
			
		int m = 1, h = 1;
		while (m + 2 * h + 3 <= n) {
			m = m + 2 * h + 3;
			h += 2;
		}
		
		if (x + y <= h-1) {
			ans = 1.0f;
		} else if (x + y > h + 1) {
			ans = 0.0f;
		} else {
			sim (h+1, y+1, n - m);
		}
		
		printf ("Case #%d: %lf\n", caze, ans);
	}
	return 0;
}
