//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//FILE *fp, *fw;
//
//int imin(int a, int b) {
//	return a < b ? a : b;
//}
//
//int main() {
//	fp = fopen("H:\\GCJ\\A-large.in", "r");
//	fw = fopen("H:\\GCJ\\outAl.txt", "wt");
//	int cse, i, n, a[1010], delta, res1, res2, g = 1;
//	fscanf(fp, "%d", &cse);
//	while(cse--) {
//		fscanf(fp, "%d", &n);
//		delta = 0;
//		for(i = 0; i < n; ++i) {
//			fscanf(fp, "%d", &a[i]);
//			if(i) {
//				if(a[i - 1] - a[i] > delta) delta = a[i - 1] - a[i];
//			}
//		}
//		//printf("delta=%d\n", delta);
//		res1 = res2 = 0;
//		for(i = 0; i < n; ++i) {
//			if(i && a[i] - a[i - 1] < 0) {
//				res1 += a[i - 1] - a[i];
//			}
//			if(i < n - 1) res2 += imin(a[i], delta);
//		}
//		fprintf(fw, "Case #%d: %d %d\n", g++, res1, res2);
//	}
//	fclose(fp);
//	fclose(fw);
//	system("PAUSE");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

#define eps 1e-4

FILE *fp, *fw;

int cnt[1000010];

int imin(int a, int b) {
	return a < b ? a : b;
}

int rev(int x) {
	int tp = 0;
	while(x > 0) {
		tp *= 10;
		tp += x % 10;
		x /= 10;
	}
	return tp;
}

int main() {
	//fp = fopen("H:\\GCJ\\B-small-attempt3.in", "r");
	fp = fopen("H:\\GCJ\\A-small-attempt0.in", "r");
	fw = fopen("H:\\GCJ\\outAs.txt", "wt");
	int cse, i, n, m, g = 1, cur, fg, tp;
	double mint, l, r, mid, maxt, rt;
	char s[15];
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(i = 1; i <= n; ++i) {
			cnt[i] = cnt[i - 1] + 1;
			tp = rev(i);
			if(!(i % 10)) continue;
			if(tp < i) cnt[i] = imin(cnt[i], cnt[tp] + 1);
		}
		fprintf(fw, "Case #%d: %d\n", g++, cnt[n]);
	}
	fclose(fp);
	fclose(fw);
	system("PAUSE");
	return 0;
}