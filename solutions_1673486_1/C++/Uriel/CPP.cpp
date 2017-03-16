//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//FILE* fw;
//
//int main() {
////	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("B-large.in", "r", stdin);
//	fw = fopen("B_l.txt", "w");
//	int cse, i, g = 1, n, s, p, ans, cnt1, cnt2, cnt3;
//	int a[110];
//	scanf("%d", &cse);
//	while(cse--) {
//		scanf("%d %d %d", &n, &s, &p);
//		for(i = 0; i < n; ++i) scanf("%d", &a[i]);
//		sort(a, a + n);
//		cnt1 = 0;
//		for(i = 0; i < n; ++i) {
//			if(a[i] >= 2) cnt1++;
//		}
//		if(cnt1 < s) {
//			fprintf(fw, "Case #%d: 0\n", g++);
//			continue;
//		}
//		if(!p) {
//			fprintf(fw, "Case #%d: %d\n", g++, n);
//			continue;
//		}
//		cnt1 = cnt2 = cnt3 = 0;
//		for(i = 0; i < n; ++i) {
//			if(a[i] >= 3 * p - 2) cnt1++;
//			else {
//				int tp = max(p - 2, 0);
//				if(2 * tp + p > a[i]) cnt3++; //CNNOUT REACH
//				else if(2 * tp + p <= a[i]) cnt2++;
//			}
//		}
////		printf("%d %d %d\n", cnt1, cnt2, cnt3);
//		if(cnt2 < s) ans = cnt1 + cnt2;
//		else
//			ans = cnt1 + s;
//		fprintf(fw, "Case #%d: %d\n", g++, ans);
//	}
//	fclose(fw);
//	return 0;
//}

//#include<stdio.h>
//int main() {
//	int p;
//	for (p = 100; p <= 200; p++) {
//		if (p % 3 != 0)
//			printf("%d\n", p);
//	}
//	printf("\n");
//	return 0;
//}






////POJ 2125
////2012.04.23
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//
//#define N 210
//#define M 15000
//#define INF 0x3f3f3f3f
//#define src 0
//#define sink 2 * n + 1
//
//int e, n, m;
//int w1[N], w2[N], d[N], vd[N], cur[N], fg[N], pre[N], co[N], cl[N];
//int ev[M], eu[M], g[M], nxt[M], head[N];
//
//void addedge(int u, int v, int w) {
//	ev[e] = v; eu[e] = u; g[e] = w; nxt[e] = head[u]; head[u] = e++;
//	ev[e] = u; eu[e] = u; g[e] = 0; nxt[e] = head[v]; head[v] = e++;
//}
//
//int aug(int pre[], int fg[]) {
//	int i, s = INF;
//	for(i = sink; i != src; i = pre[i]) s = min(s, g[fg[i]]);
//	for(i = sink; i != src; i = pre[i]) g[fg[i]] -= s, g[fg[i] ^ 1] += s;
//	return s;
//}
//
//int ISAP() {
//	int now, ans = 0, p, nd;
//	memset(d, 0, sizeof(d));
//	memset(vd, 0, sizeof(vd));
//	cur[now = src] = head[src];
//	vd[0] = 2 * n + 2;
//	while(d[src] < 2 * n + 2) {
//		if(now == sink) ans += aug(pre, fg), now = src;
//		for(p = cur[now]; ~p; p = nxt[p]) {
//			nd = ev[p];
//			if(g[p] && d[now] == d[nd] + 1) {
//				cur[now] = p;
//				break;
//			}
//		}
//		if(~p) pre[nd] = now, fg[nd] = p, now = nd;
//		else {
//			cur[now] = head[now];
//			if(--vd[d[now]] == 0) break;
//			vd[++d[now]]++;
//			if(now != src) now = pre[now];
//		}
//	}
//	return ans;
//}
//
//void DFS1(int x) {
//	co[x] = 1;
//	for(int i = head[x]; ~i; i = nxt[i]) {
//		if(i & 1) continue;
//		if(!co[ev[i]] && g[i]) DFS1(ev[i]);
//	}
//}
//
//void DFS2(int x) {
//	cl[x] = 1;
//	for(int i = head[x]; ~i; i = nxt[i]) {
//		if(!(i & 1)) continue;
//		if(!cl[ev[i]] && g[i - 1]) DFS2(ev[i]);
//	}
//}
//
//int main() {
//	int i, a, b, k, ans;
//	while(~scanf("%d %d", &n, &m)) {
//		e = 0;
//		memset(head, -1, sizeof(head));
//		for(i = 1; i <= n; ++i) {
//			scanf("%d", &w1[i]);
//			addedge(n + i, sink, w1[i]);
//		}
//		for(i = 1; i <= n; ++i) {
//			scanf("%d", &w2[i]);
//			addedge(src, i, w2[i]);
//		}
//		for(i = 0; i < m; ++i) {
//			scanf("%d %d", &a, &b);
//			addedge(a, b + n, INF);
//		}
//		ans = ISAP();
//		printf("%d\n", ans);
//		memset(co, 0, sizeof(co));
//		DFS1(0);
//		memset(cl, 0, sizeof(cl));
//		DFS2(2 * n + 1);
////		k = 0;
////		for(i = 1; i <= n; ++i) {
////			if(!co[i]) ++k;
////			if(co[i + n]) ++k;
////		}
////		printf("%d\n", k);
////		for(i = 1; i <= n; ++i) {
////			if(!co[i]) printf("%d -\n", i);
////			if(co[i + n]) printf("%d +\n", i);
////		}
////		puts("");
//		k = 0;
////		for(i = 0; i < 12; ++i) if(!g[i]) printf("%d\n", i);
//		for(i = 0; i < e; i += 2) {
//			if(co[eu[i]] && cl[ev[i]] && !g[i]) k++;
//		}
//		printf("%d\n", k);
//		for(i = 0; i < e; i += 2) {
//			if(co[eu[i]] && cl[ev[i]] && !g[i] && ev[i] <= n) printf("%d -\n", ev[i]);
//			else if(co[eu[i]] && cl[ev[i]] && !g[i] && eu[i] > n) printf("%d +\n", eu[i] - n);
//		}
//	}
//	return 0;
//}



//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<algorithm>
//using namespace std;
//#define N 1010
//
//struct lev1{
//	int star, id;
//}l1[N];
//
//struct lev2{
//	int star, id;
//}l2[N];
//
//bool cmp1(lev1 a, lev1 b) {
//	return a.star < b.star;
//}
//
//bool cmp2(lev2 a, lev2 b) {
//	return a.star < b.star;
//}
//
//int fi[N];
//FILE* fw;
//
//int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
////	freopen("B-large.in", "r", stdin);
//	fw = fopen("B_s0.txt", "w");
//	int cse, n, cnt, i, sum, fg, ans, g = 1;
//	scanf("%d", &cse);
//	while(cse--) {
//		scanf("%d", &n);
//		for(i = 0; i < n; ++i) {
//			scanf("%d %d", &l1[i].star, &l2[i].star);
//			l1[i].id = i;
//			l2[i].id = i;
//		}
//		sort(l1, l1 + n, cmp1);
//		sort(l2, l2 + n, cmp2);
//		memset(fi, 0, sizeof(fi));
//		cnt = sum = ans = 0;
//		fg = 1;
//		while(cnt < n && fg) {
//			printf("cnt = %d\n", cnt);
//			fg = 0;
//			for(i = 0; i < n; ++i) {
//				if(!fi[l2[i].id] && l2[i].star <= sum) {
//					fg = 1;
//					fi[l2[i].id] = 2;
//					sum += 2;
//					ans++;
//					cnt++;
//				}
//				else if(fi[l2[i].id] == 1 && l2[i].star <= sum) {
//					fg = 1;
//					fi[l2[i].id] = 2;
//					sum++;
//					ans++;
//					cnt++;
//				}
//				else if(l2[i].star > sum) break;
//			}
//			if(!fg) {
//				for(i = 0; i < n; ++i) {
//					if(!fi[l1[i].id] && l1[i].star <= sum) {
//						fg = 1;
//						fi[l1[i].id] = 1;
//						ans++;
//						sum++;
//						break;
//					}
//					else if(l1[i].star > sum) break;
//				}
//			}
//		}
//		if(cnt == n) {
//			fprintf(fw, "Case #%d: %d\n", g++, ans);
//		}
//		else {
//			fprintf(fw, "Case #%d: Too Bad\n", g++);
//		}
//	}
//	fclose(fw);
//	return 0;
//}





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 200000

int A, B;
double co[N];
FILE* fw;

int main() {
//	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	fw = fopen("A_l.txt", "w");
	int cse, st, fg, n1, n2, g = 1, i;
	double p, ans, mi;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d %d", &A, &B);
		fg = 0;
		for(i = 1; i <= A; ++i) {
			scanf("%lf", &co[i]);
//			if(!fg && co[i] < 1) fg = i;
		}
//		printf("fg = %d\n", fg);
		//keep
		p = 1.0;
		for(i = 1; i <= A; ++i) {
			p *= co[i];
		}
		n1 = B - A + 1;
		n2 = n1 + B + 1;
		mi = n1 * p + n2 * (1 - p);
//		printf("mi=%lf\n", mi);
		//1~A
		for(st = 1; st <= A; ++st) {
			p = 1.0;
			for(i = 1; i <= A - st; ++i) {
				p *= co[i];
			}
			n1 = B - A + 1 + st * 2;
			n2 = n1 + B + 1;
			ans = p * n1 + n2 * (1 - p);
			mi = min(mi, ans);
//			printf("%d %d %lf\n", n1, n2, p);
		}

		//enter now
		if(A == B) {
			p = 1.0;
			for(i = 1; i <= A; ++i) {
				p *= co[i];
			}
			ans = p * 1 + (1 - p) * (B + 2);
			mi = min(mi, ans);
		}
		else {
			mi = min(1.0 * (B + 2), mi);
		}
		fprintf(fw, "Case #%d: %lf\n", g++, mi);
	}
	fclose(fw);
	return 0;
}
