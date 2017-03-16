#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 1010

FILE *fw;

struct M {
	double t, a, b;
}p[N];

int sp[N], nt;

int main() {
	freopen("A-small-attempt2.in", "r", stdin);
//	freopen("A-large.in", "r", stdin);
	fw = fopen("A_s2.txt", "w");
	int cse, i, n, g = 1, k, nn;
	double sum, cnt, mx;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d", &n);
		sum = cnt = 0.0;
		mx = 1000.0;
		for(i = 0; i < n; ++i) {
			scanf("%lf", &p[i].t);
			sum += p[i].t;
			if(p[i].t < mx) {
				mx = p[i].t;
				k = i;
			}
		}
		for(i = 0; i < n; ++i) {
			if(i == k) continue;
			p[i].a = (p[k].t - p[i].t) / sum;
			cnt += p[i].a;
		}
		cnt *= -1;
		cnt += 1.0;
		cnt /= (1.0 * n);
		nt = 1;
//		puts("**");
////		if(cnt >= 0.0)
//			fprintf(fw, "Case #%d: %lf", g++, 100.0 * cnt);
////		else
////			fprintf(fw, "Case #%d: %lf", g++, 0);
//		for(i = 1; i < n; ++i) {
////			if(100.0 * (cnt + p[i].a) >= 0.0)
//				fprintf(fw, " %lf", 100.0 * (cnt + p[i].a));
////			else
////				fprintf(fw, " %lf", 0);
		memset(sp, 0, sizeof(sp));
		for(i = 0; i < n; ++i) {
			if(i != k && 100.0 * (cnt + p[i].a) < 0.0)
				sp[i] = 1;
		}
		cnt = 0.0;
		for(i = 0; i < n; ++i) {
			if(!sp[i] && i != k) {
				p[i].a = (p[k].t - p[i].t) / sum;
				cnt += p[i].a;
				nt++;
			}
		}
		cnt *= -1;
		cnt += 1.0;
		cnt /= (1.0 * nt);
		nn = 0;
		fprintf(fw, "Case #%d:", g++);
		for(i = 0; i < n; ++i) {
			if(sp[i]) fprintf(fw, " 0.000000");
			else if(i == k) fprintf(fw, " %lf", 100 * cnt);
			else {
				fprintf(fw, " %lf", 100.0 * (cnt + p[i].a));
			}
		}
		fprintf(fw, "\n");
	}
	fclose(fw);
	return 0;
}


//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 20
//#define M 2000010
//
//int a[N], fg[M], mk[M], ans[N], na, usd[N];
//
//FILE *fw;
//
//int main() {
//	//	freopen("C-small-attempt0.in", "r", stdin);
//	//	freopen("A-large.in", "r", stdin);
//	fw = fopen("C_s0.txt", "w");
//	int g = 1, k, cse, i, j, sum, cnt, nn, tp, ok;
//	scanf("%d", &cse);
//	while (cse--) {
//		sum = 0;
//		for (i = 0; i < N; ++i) {
//			scanf("%d", &a[i]);
//			sum += a[i];
//		}
//		fprintf(fw, "Case #%d:\n", g++);
//		ok = 0;
////		printf("sum=%d\n", sum);
//		for (k = 2; k <= sum && !ok; k += 2) {
//			printf("k=%d\n", k);
//			cnt = 0;
//			memset(fg, 0, sizeof(fg));
//			memset(mk, 0, sizeof(mk));
//			memset(usd, 0, sizeof(usd));
//			tp = k >> 1;
//			fg[0] = 1;
////			printf("tp=%d\n", tp);
////			printf("---%d\n", fg[tp]);
//			for (i = 0; i < N; ++i) {
//				for (j = tp - a[i]; j >= 0; --j) {
//					if(!fg[j]) continue;
//					fg[j + a[i]] = 1;
//					mk[j + a[i]] = mk[j] | (1 << i);
////					if(fg[tp]) {
////						printf("i=%d\n", i);
////					}
//					if(fg[tp]) break;
//				}
//				if(fg[tp]) break;
//			}
////			printf("fp[%d] = %d %d\n", tp, fg[tp], mk[tp]);
//			if (fg[tp]) {
////				printf("tp=%d\n", tp);
//				na = 0;
//				for (i = 0; i < N; ++i) {
//					if (mk[tp] & (1 << i)) {
//						ans[na++] = i;
//						usd[i] = 1;
//					}
//				}
//				if(tp == 20)for(i = 0; i < N; ++i) {
//					p
//				}
////				printf("tp=%d\n", mk[tp]);
////				for(i = 0; i < N; ++i) printf("usd[%d] = %d\n", i, usd[i]);
////				for(i = 0; i < na; ++i) printf("ans=%d\n", a[ans[i]]);
//				memset(fg, 0, sizeof(fg));
//				memset(mk, 0, sizeof(mk));
//				fg[0] = 1;
//				for (i = 0; i < N; ++i) {
//					if(usd[i]) continue;
//					for (j = tp - a[i]; j >= 0; --j) {
//						if(!fg[j]) continue;
//						if(mk[j] & (1 << i)) continue;
//						fg[j + a[i]] = 1;
//						mk[j + a[i]] = mk[j] | (1 << i);
//					}
//				}
//				if(fg[tp]) {
//					printf("tp=%d\n");
//					ok = 1;
//					fprintf(fw, "%d", a[ans[0]]);
//					for(i = 1; i < na; ++i) fprintf(fw, " %d", a[ans[i]]);
//					nn = 0;
//					fprintf(fw, "\n");
//					for(i = 0; i < N; ++i) {
//						if (!nn && mk[tp] & (1 << i)) {
//							fprintf(fw, "%d", a[i]);
//						}
//						else if(nn && mk[tp] & (1 << i)) {
//							fprintf(fw, " %d", a[i]);
//						}
//					}
//					fprintf(fw, "\n");
//				}
//				else
//					continue;
//			}
//			else
//				continue;
//		}
//		if(!ok) fprintf(fw, "Impossible\n");
//	}
//	fclose(fw);
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 20
//#define M 2000010
//
//int a[N], fg[M], mk[M], ans[N], na, usd[N];
//
//FILE *fw;
//
//int main() {
//		freopen("C-small-attempt0.in", "r", stdin);
//	//	freopen("A-large.in", "r", stdin);
//	fw = fopen("C_s0.txt", "w");
//	int g = 1, k, h, cse, i, j, sum, cnt, nn, tp, ok;
//	scanf("%d", &cse);
//	while (cse--) {
//		sum = 0;
//		scanf("%d", &i);
//		for (i = 0; i < N; ++i) {
//			scanf("%d", &a[i]);
//			sum += a[i];
//		}
//		fprintf(fw, "Case #%d:\n", g++);
//		for(i = 1; i < (1 << N); ++i) {
//			k = 0;
//			for(j = 0; j < N; ++j) {
//				if(i & (1 << j)) k += a[j];
//			}
//			printf("k=%d\n", k);
//			memset(fg, 0, sizeof(fg));
//			memset(mk, 0, sizeof(mk));
//			fg[0] = 1;
//			for(j = 0; j < N; ++j) {
//				if(i & (1 << j)) continue;
//				for(h = k - a[j]; h >= 0; --h) {
//					if(!fg[h]) continue;
//					fg[h + a[j]] = 1;
//					mk[h + a[j]] = mk[h] | (1 << j);
//					if(fg[k]) break;
//				}
//				if(fg[k]) break;
//			}
//			puts("**");
//			if(fg[k]) {
//				nn = 0;
//				for(j = 0; j < N; ++j) {
//					if(!nn && (i & (1 << j))) {
//						fprintf(fw, "%d", a[j]);
//						nn = 1;
//					}
//					else if(nn && (i & (1 << j))) fprintf(fw, " %d", a[j]);
//				}
//				fprintf(fw, "\n");
//				nn = 0;
//				for(j = 0; j < N; ++j) {
//					if(!nn && (mk[k] & (1 << j))) {
//						fprintf(fw, "%d", a[j]);
//						nn = 1;
//					}
//					else if(nn && (mk[k] & (1 << j))) fprintf(fw, " %d", a[j]);
//				}
//				fprintf(fw, "\n");
//				break;
//			}
//		}
//		if(i == (1 << N)) fprintf(fw, "Impossible\n");
//	}
//	fclose(fw);
//	return 0;
//}
