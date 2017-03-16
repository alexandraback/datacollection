#include <stdio.h>
#include <stdlib.h>
int T, N, M, C=1, i, j, k, l,A[11][35][35],L[11][35],temp[35],Now1[35],Now2[35],NC,count,Prime[100000],Pc,Print[11];
bool check[1000005];
int isprime() {
	NC = 0;
	for (i = 2; i <= 10; i++) {
		for (j = 0; j <= 33; j++) Now2[j] = 0;
		NC = 0;
		for (j = 0; j <= N-1; j++) {
			if (Now1[N-j] == 1) {
				l = (NC < L[i][j]) ? L[i][j] : NC;
				for (k = 0; k <= 33; k++) temp[k] = 0;
				int k1 = L[i][j], k2 = NC;
				for (k = l; k >= 1; k--) {
					temp[k] += A[i][j][k1] + Now2[k2];
					if(k1!=0) k1--; 
					if(k2!=0) k2--;
					while (temp[k] >= 10) {
						temp[k] -= 10; temp[k - 1]++;
					}
				}
				if (temp[0] > 0) {
					NC = l + 1;
					for (k = NC; k >= 1; k--) Now2[k] = temp[k - 1];
				}
				else {
					NC = l;
					for (k = NC; k >= 1; k--) Now2[k] = temp[k];
				}
			}
		}
		int t1 = 1, t2 = 0;
		for (j = NC; j >= 1; j--) {
			t2 += Now2[j] * t1;
			if (t2 >= 1000000) {
				t2 = -1; break;
			}
			t1 *= 10;
		}
		for (j = 1; j <= Pc; j++) {
			if (t2 != -1 && t2 <= Prime[j]) {
				j = Pc + 1; break;
			}
			if (t2 != -1) {
				if (t2%Prime[j] == 0) {
					Print[i] = Prime[j];
					break;
				}
			}
			else {
				l = 0;
				for (k = 1; k <= NC; k++) {
					l = l * 10 + Now2[k];
					if (l >= Prime[j]) l %= Prime[j];
				}
				if (l == 0) {
					Print[i] = Prime[j];
					break;
				}
			}
		}
		if (j == Pc + 1) return 1;
	}
	for (i = 1; i <= N; i++) printf("%d", Now1[i]);
	for (i = 2; i <= 10; i++) printf(" %d", Print[i]);
	printf("\n");
	return 0;
}
void back(int x) {
	if (x == N) {
		if (!isprime()) {
			count++;
			if (count == M) exit(0);
		}
		return;
	}
	Now1[x] = 1;
	back(x + 1);
	Now1[x] = 0;
	back(x + 1);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (i = 2; i <= 1000000; i++) {
		if (check[i] == 0) {
			Prime[++Pc] = i;
			j = i;
			for (; j <= 1000000; j += i) {
				check[j] = 1;
			}
		}
	}
	for (i = 2; i <= 10; i++) A[i][0][1] = L[i][0] = 1;
	for (j = 1; j <= 32; j++) {
		for (i = 2; i <= 10; i++) {
			for (k = 0; k <= 33; k++) temp[k] = 0;
			for (k = L[i][j - 1]; k >= 1; k--) {
				temp[k] += A[i][j - 1][k] * i;
				while (temp[k] >= 10) {
					temp[k] -= 10; temp[k - 1]++;
				}
			}
			if (temp[0] > 0) {
				L[i][j] = L[i][j - 1] + 1;
				for (k = L[i][j]; k >= 1; k--) {
					A[i][j][k] = temp[k - 1];
				}
			}
			else {
				L[i][j] = L[i][j - 1];
				for (k = L[i][j]; k >= 1; k--) {
					A[i][j][k] = temp[k];
				}
			}
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		printf("Case #1:\n");
		Now1[1] = Now1[N] = 1;
		back(2);
	}
}