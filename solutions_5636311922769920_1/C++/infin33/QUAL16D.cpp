#include <stdio.h>
int T, K, C, S, i, j, k, l, Co, Now[105], Pow[105][2], mul, Pc, Pos;
long long Print[105];
long long whe() {
	long long ret = 1, fact = 1;
	for (int i = C; i >= 1; i--) {
		ret += fact*(Now[i] - 1);
		fact *= K;
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		++Co;
		printf("Case #%d:", Co);
		scanf("%d %d %d", &K, &C, &S);
		Pos = Pow[1][0] = mul = 1; Pc = Pow[1][1] = 0;
		if (C > K) C = K;
		if (C == 1) {
			if(S<K) printf(" IMPOSSIBLE");
			else {
				for (i = 1; i <= K; i++) printf(" %d", i);
			}
			printf("\n");
			continue;
		}
		if (C == 2) {
			for (i = 1; i <= K; i += 2) {
				S--;
				Now[1] = i; Now[2] = i + 1;
				if (i + 1 > K) Now[2] = i;
				Print[++Pc] = whe();
			}
			if (S < 0) printf(" IMPOSSIBLE"); 
			else {
				for (i = 1; i <= Pc; i++) printf(" %lld", Print[i]);
			}
			printf("\n");
			continue;
		}
		for (i = 2;; i++) {
			mul *= (C-1);
			Pow[i][0] = Pow[i - 1][0] + mul;
			if (Pow[i][0] > K) break;
		}
		int KK = K;
		for (j = i - 1; j >= 1; j--) {
			while (KK >= Pow[j][0]) {
				Pow[j][1]++; KK -= Pow[j][0];
			}
		}
		int flag = 0;
		for (j = i; j >= 2; j--) {
			while (Pow[j][1] >= 1) {
				int p1 = Pos, p2 = Pos + Pow[j][0] - Pow[j - 1][0];
				for (k = 1; k <= Pow[j - 1][0]; k++) {
					for (l = 1; l <= C - 1; l++) Now[l] = p1++;
					Now[C] = p2++;
					Print[++Pc] = whe();
				}
				Pos = p2;
				S -= Pow[j - 1][0];
				Pow[j][1]--;
			}
		}
		if (Pow[1][1] > 0) {
			for (j = 1; j <= Pow[1][1]; j++) {
				Now[j] = Pos++;
			}
			--Pos;
			for (; j <= C; j++) {
				Now[j] = Pos;
			}
			Print[++Pc] = whe();
			S--;
		}
		if (S >= 0) {
			for (i = 1; i <= Pc; i++) printf(" %lld", Print[i]);
		}
		else printf(" IMPOSSIBLE");
		printf("\n");
	}
}