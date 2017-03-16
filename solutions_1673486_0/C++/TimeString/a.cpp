#include <stdio.h>

int main() {
	int ecase;
	double ep[100000];
	double frontCorrectP[100000];

	scanf("%d", &ecase);
	for (int ecount = 1; ecount<=ecase; ecount++) {
		int ea, eb;
		double thisFalseP;
		double lastCorrectP = 1.0;
		scanf("%d%d", &ea, &eb);
		for (int i = 0; i < ea; i++) {
			scanf("%lf", &ep[i]);
		}
		frontCorrectP[0] = 1.0;
		for (int i = 1; i <= ea; i++)
			frontCorrectP[i] = frontCorrectP[i-1] * ep[i-1];
		double ans = 2 + eb;
		for (int i = 0; i <= ea; i++) {
			double tp = frontCorrectP[ea-i] * (i + eb-(ea-i) + 1);
			double fp = (1.0 - frontCorrectP[ea-i]) * (i + eb-(ea-i) + 1 + eb + 1);
			if (tp + fp < ans)
				ans = tp + fp;
		}
		printf("Case #%d: %lf\n", ecount, ans);
	}

	return 0;
}
