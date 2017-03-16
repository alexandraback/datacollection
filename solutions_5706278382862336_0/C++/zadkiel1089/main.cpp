//#include <cstdio>
//#include <cstring>
//
//int main() {
//	//freopen("A-small-attempt1.in", "r", stdin);
//	//freopen("output.txt", "w", stdout);
//	int T, casenum = 1;
//	scanf("%d", &T);
//	while (T--) {
//		int n, count[100][105];
//		char str[100][105], ch[100][105];
//		scanf("%d", &n);
//		for (int i = 0; i < n; i++) {
//			scanf("%s", str[i]);
//			int now = 1, chnow = 0;
//			ch[i][0] = str[i][0]; count[i][0] = 1;
//			while (str[i][now] != 0) {
//				if (str[i][now] == str[i][now - 1]) count[i][chnow]++;
//				else {
//					count[i][++chnow] = 1;
//					ch[i][chnow] = str[i][now];
//				}
//				now++;
//			}
//			ch[i][chnow + 1] = '\0';
//		}
//		bool same = true;
//		for (int i = 0; same && i < n; i++)
//			for (int j = i + 1; same && j < n; j++)
//				same = (strcmp(ch[i], ch[j]) == 0);
//		printf("Case #%d: ", casenum++);
//		if (!same) {
//			printf("Fegla Won\n");
//		}
//		else {
//			int ans = 0;
//			for (int i = 0; ch[0][i] != '\0'; i++) {
//				int avg = 0;
//				for (int j = 0; j < n; j++)
//					avg += count[j][i];
//				avg /= n;
//				for (int j = 0; j < n; j++)
//					ans += (avg > count[j][i]) ? avg - count[j][i] : count[j][i] - avg;
//			}
//			printf("%d\n", ans);
//		}
//	}
//	return 0;
//}

//#include <cstdio>
//
//int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int T, casenum = 1;
//	scanf("%d", &T);
//	while (T--) {
//		int A, B, K, ans=0;
//		scanf("%d %d %d", &A, &B, &K);
//		printf("Case #%d: ", casenum++);
//		for (int i = 0; i < A; i++)
//			for (int j = 0; j < B; j++)
//				ans += ((i&j) < K);
//		printf("%d\n", ans);
//	}
//}

//#include <cstdio>
//
//int main() {
//	int T, casenum = 1;
//	scanf("%d", &T);
//	while (T--) {
//		
//	}
//}

#include <cstdio>

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, casenum = 1;
	scanf("%d", &T);
	while (T--) {
		int P, Q;
		scanf("%d/%d", &P, &Q);
		printf("Case #%d: ", casenum++);
		if (Q != 1 && Q != 2 && Q != 4 && Q != 8 && Q != 16 && Q != 32 && Q != 64 && Q != 128 && Q != 256 && Q != 512) printf("impossible\n");
		else {
			int count = 0;
			while (P < Q) { P *= 2; count++; }
			printf("%d\n", count);
		}
	}
}