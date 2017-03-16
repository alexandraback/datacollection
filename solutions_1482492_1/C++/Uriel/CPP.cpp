//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 2010
//
//int n, mp[N][N], cnt[N][N], q[N], vis[N];
//FILE *fw;
//bool ok;
//
//struct node {
//	int n;
//	int id[N];
//}p[N];
//
//void BFS(int x) {
//	int i, l = 0, r = 1, tx;
//	q[0] = x;
//	memset(vis, 0, sizeof(vis));
//	while(l < r) {
////		printf("q[%d]=%d\n", l, q[l]);
//		tx = q[l];
//		for(i = 0; i < n; ++i) {
//			if(mp[tx][i] && !vis[i]) {
//				q[r] = i;
//				cnt[x][i]++;
//				vis[i] = 1;
//				++r;
//			}
//			else if(mp[tx][i] && vis[i]) {
//				cnt[x][i]++;
//				if(cnt[x][i] > 1) {
//					ok = true;
//					return;
//				}
//			}
//		}
//		++l;
//	}
//	puts("");
//}
//
//int main() {
////	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("A-large.in", "r", stdin);
//	fw = fopen("A_l.txt", "w");
//	int g = 1, cse, i, j;
//	scanf("%d", &cse);
//	while (cse--) {
//		scanf("%d", &n);
//		memset(mp, 0, sizeof(mp));
//		memset(cnt, 0, sizeof(cnt));
//		for(i = 0; i < n; ++i) {
//			scanf("%d", &p[i].n);
//			for(j = 0; j < p[i].n; ++j) {
//				scanf("%d", &p[i].id[j]);
//				mp[i][p[i].id[j] - 1] = 1;
//			}
//		}
////		for(i = 0; i < n; ++i) {
////			for(j = 0; j < n; ++j) {
////				printf("%d ", mp[i][j]);
////			}
////			puts("");
////		}
//		ok = false;
//		for(i = 0; !ok && i < n; ++i) {
//			BFS(i);
//		}
//		if(ok) fprintf(fw, "Case #%d: Yes\n", g++);
//		else
//			fprintf(fw, "Case #%d: No\n", g++);
//	}
//	fclose(fw);
//	return 0;
//}

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 2010

FILE *fw;

struct seg {
	double t, pos;
}p[N];

int n, A;
double d;

int main() {
//	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	fw = fopen("B_l.txt", "w");
	int g = 1, cse, i, j;
	double a, v0, aa, bb, cc, tp1, tp2, delta, x, tt, pp, vv, cntt, s, rep, ft;
	scanf("%d", &cse);
	while (cse--) {
		scanf("%lf %d %d", &d, &n, &A);
		for(i = 0; i < n; ++i) {
			scanf("%lf %lf", &p[i].t, &p[i].pos);
		}
		fprintf(fw, "Case #%d:\n", g++);
		for(i = 0; i < A; ++i) {
			scanf("%lf", &a);
			tp1 = 0.0;
			v0 = 0.0;
			cntt = 0.0;
			if(n == 1) {
				aa = 0.5 * a;
				cntt = sqrt(d / aa);
			}
			else {
				for(j = 0; j < n - 1; ++j) {
					if(j < n - 2) {
						tt = p[j + 1].t - p[j].t;
						pp = p[j + 1].pos - p[j].pos;
						vv = pp / tt;
						aa = 0.5 * a;
						tp2 = p[j].pos;
						bb = v0 - vv;
						cc = tp1 - p[j].pos;
						delta = bb * bb - 4.0 * aa * cc;
						ft = p[j + 1].t;
					}
					else {
						tt = p[j + 1].t - p[j].t;
						pp = p[j + 1].pos - p[j].pos;
	//					printf("pp=%lf tt=%lf\n", pp, tt);
						vv = pp / tt;
						pp = d - p[j].pos;
						tt = pp / vv;
						ft = tt + p[j].t;
						aa = 0.5 * a;
						tp2 = p[j].pos;
						bb = v0 - vv;
						cc = tp1 - p[j].pos;
						delta = bb * bb - 4.0 * aa * cc;
	//					printf("%lf %lf %lf~\n", aa, bb, cc);
	//					printf("del=%lf\n", delta);
					}
					if(delta < 0.0) {
						tp1 += v0 * tt + aa * tt * tt;
						v0 += a * tt;
						cntt += tt;
					}
					else {
						x = (sqrt(delta) -bb)/ (2 * aa);
	//					printf("x=%lf\n", x);
	//					printf("tt=%lf\n", tt);
						if(x > ft && j < n - 2) {
							tp1 += v0 * tt + aa * tt * tt;
							v0 += a * tt;
							cntt += tt;
						}
						else if(x > ft && j == n - 2) {
							bb = v0;
							cc = tp1 - d;
							delta = bb * bb - 4.0 * aa * cc;
	//						printf("delta = %lf\n", delta);
							x = (sqrt(delta) -bb)/ (2 * aa);
							cntt += x;
						}
						else{
							if(j == n - 2) {
								cc = d - tp1;
								cc -= tt * v0;
								x = sqrt(cc / aa);
								v0 += a * x;
								cntt += tt;
								tp1 = d;
							}
							else {
								cc = p[j + 1].pos - tp1;
								cc -= tt * v0;
								x = sqrt(cc / aa);
								v0 += a * x;
								cntt += tt;
								tp1 = p[j + 1].pos;
							}
						}
					}
				}
			}
			fprintf(fw, "%lf\n", cntt);
		}

	}
	fclose(fw);
	return 0;
}




//#include<math.h>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 2010
//
//FILE *fw;
//
//int main() {
////	freopen("A-small-attempt0.in", "r", stdin);
////	freopen("B-large.in", "r", stdin);
//	fw = fopen("B_s0.txt", "w");
//	int g = 1, cse, i, j;
//	scanf("%d", &cse);
//	while (cse--) {
//
//	}
//	fclose(fw);
//	return 0;
//}
