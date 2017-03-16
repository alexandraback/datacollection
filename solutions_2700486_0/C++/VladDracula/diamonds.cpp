#include <stdio.h>

#define INFILE		"diamonds.in"
#define OUTFILE		"diamonds.out"

int abs(int a) {
	return a < 0 ? -a : a;
}

int inlevel(int x, int y) {
	int cnt = 1;
	if (x==0 && y==0) return 0;
	int l;
	for (l=1; cnt<(1<<20); l++) {
		cnt += 4 * l + 1;
		if (x >= -2*l && x <= 2*l && y >= 0 && y <= 2*l && abs(x)+y==2*l)
			return l;
	}
	return l;
}

void minval(int x, int l, int &minL, int &minR) {
	if (x < 0) {
		minL = 2*l - abs(x) + 1;
		minR = 0;
	} else
	if (x > 0) {
		minL = 0;
		minR = 2*l - x + 1;
	} else
		minL = minR = -1;
}

double prob[1024][1024];

void solve(FILE *fin, FILE *fout) {
	int tests;
	fscanf(fin, "%d", &tests);

	int n, x, y;
	for (int t=0; t<tests; t++) {
		fscanf(fin, "%d%d%d", &n, &x, &y);

		int posl = inlevel(x, y);

		int prev = 0;
		int cnt = 1;
		int l = 0;
		while (cnt < n) {
			prev =  cnt;
			l++;
			cnt += 4 * l + 1;
		}

		double ans = 0.0;
		if (n == cnt && posl <= l)
			ans = 1.0;
		else if (posl < l)
			ans = 1.0;
		else if (posl > l)
			ans = 0.0;
		else {
			int minL, minR;
			minval(x, posl, minL, minR);

			prob[0][0] = 1.0;
			prob[0][1] = 0.0;
			for (int num=1; num<=n-prev; num++) {
				for (int left=0, right=num; left<=num && left <= 2*l; left++, right--) {
					prob[num][left] = prob[num-1][left] * 0.5;
					if (left > 0)
						prob[num][left] += prob[num-1][left-1] * 0.5;
				}
				prob[num][num+1]=0.0;
			}

			int num = n - prev;
			for (int left=0; left <= num && left <= 2*l; left++)
				if (left>=minL && num-left>=minR)
					ans += prob[num][left];

			if (minL == -1)
				ans = 0.0;
		}
		
		fprintf(fout, "Case #%d: %.8lf\n", t+1, ans);
	}

}

int main() {
	FILE *fin = fopen(INFILE, "r");
	FILE *fout = fopen(OUTFILE, "w");
	if (!fin) {
		printf("Cannot open input file!\n");
		return 0;
	}
	if (!fout) {
		printf("Cannot open output file!\n");
		return 0;
	}

	solve(fin, fout);

	fclose(fin);
	fclose(fout);
	return 0;
}
