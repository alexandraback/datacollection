#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
int Mini(int x, int y) {
	return x < y ? x : y;
}
int Maxi(int x, int y) {
	return x > y ? x : y;
}
struct sg {
	int x;
	int y;
	bool friend operator < (const sg i, const sg j) {
		return i.x < j.x;
	}
}v[101];
int T, Co, i, j, k, l, N, data[1005], Fol[1005],Ans,C1[1005],FF[1005][3],Fc,M1,M2;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		Co++;
		printf("Case #%d: ", Co);
		Ans = Fc = 0;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			Fol[i] = 0;  scanf("%d", &data[i]);
		}
		for (i = 1; i <= N; i++) {
			if (data[i] == -1) continue;
			for (j = 1; j <= N; j++) C1[j] = 0;
			k = 1; j = i; C1[i] = 1;
			if (data[data[i]] == i) {
				FF[++Fc][0] = i; FF[Fc][1] = data[i]; data[data[i]] = -1; data[i] = -1;
				continue;
			}
		}
		for (i = 1; i <= N; i++) {
			if (data[i] == -1) continue;
			for (j = 1; j <= N; j++) C1[j] = 0;
			j = i; k = 1;  C1[i] = 1;
			while (1) {
				if (data[j] == i) {
					if (Ans < k) Ans = k;
					break;
				}
				if (data[j] == -1) {
					if (Fol[j] < k-1) Fol[j] = k-1;
					break;
				}
				if(C1[data[j]] == 1) break;
				j = data[j]; k++; C1[j] = 1;
			}
		}
		M1 = 0;
			for (i = 1; i <= Fc; i++) {
				k = Fol[FF[i][0]]; l = Fol[FF[i][1]];
				M1 += k + l + 2;
			}
			if (Ans < M1) Ans = M1;
			printf("%d\n", Ans);
	}
	return 0;
}