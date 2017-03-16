#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int NMAX = 2000;

int N;
char A[NMAX + 5][25];
char B[NMAX + 5][25];
int LA[NMAX + 5];
int LB[NMAX + 5];
int F[NMAX + 5];
bitset < NMAX + 5 > samefirst[NMAX + 5];
bitset < NMAX + 5 > samesecond[NMAX + 5];
int P[NMAX + 5];
int Q[NMAX + 5];
bitset < NMAX + 5 > fir, sec;

int solve() {
	unordered_map<string, int> fw, sw;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%s %s", A[i], B[i]);
		LA[i] = strlen(A[i]);
		LB[i] = strlen(B[i]);
		if (fw.count(A[i])) P[i] = fw[A[i]];
		else P[i] = fw[A[i]] = i;
		if (sw.count(B[i])) Q[i] = sw[B[i]];
		else Q[i] = sw[B[i]] = i;
	}

	// for (int i = 1; i <= N; i++)
	// 	printf("%d %d\n", P[i], Q[i]);

	// return 0;

	for (int i = 1; i <= N; i++) {
		samefirst[i] = 0;
		samesecond[i] = 0;
		for (int j = 1; j <= N; j++) {
			if (P[i] == P[j] && i != j)
				samefirst[i][j] = 1;
			if (Q[i] == Q[j] && i != j)
				samesecond[i][j] = 1;
		}
	}

	int nr = 0, nrm = N;

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++)
			cnt |= (samefirst[i][j] << 1) | (samesecond[i][j]);
		if (cnt != 3) F[++nr] = i;
		else F[nrm--] = i;
	}

	// printf("\n");
	// for (int i = 1; i <= N; printf(" %s %s\n", A[i], B[i]), i++)
	// 	for (int j = 1; j <= N; j++)
	// 		printf("%d%d ", (int)samefirst[i][j], (int)samesecond[i][j]);

	int sol = 0;

	sort(F + nr + 1, F + N + 1);

	// for (int i = 1; i <= N; i++)
	// 	printf("%d ", F[i]);
	// printf("\n");
	// fflush(stdout);

	if (3 * nr < N)
		return N - max(fw.size(), sw.size());

	do {
		fir = 0;
		sec = 0;

		int cnt = 0;

		for (int i = 1; i <= N; i++) {
			if (fir[P[F[i]]] && sec[Q[F[i]]]) cnt++;
			fir[P[F[i]]] = 1;
			sec[Q[F[i]]] = 1;
			if (cnt + (N - i) < sol) break;
		}

		sol = max(sol, cnt);

	} while (next_permutation(F + nr + 1, F + N + 1));

	return sol;
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int nrtests;

	scanf("%d", &nrtests);

	for (int testnr = 1; testnr <= nrtests; testnr++) {
		printf("Case #%d: ", testnr);
		printf("%d", solve());
		printf("\n");
	}

	return 0;
}