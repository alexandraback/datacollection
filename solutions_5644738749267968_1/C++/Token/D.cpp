/*
 * 2014-04-12  Token  <token@token-HP-ENVY-14-SPECTRE-Notebook-PC>

 * 
 */
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++ i)

const int MaxiN = 1005;

int N, Ans1, Ans2;
double A[MaxiN], B[MaxiN];

void Import() {
	scanf("%d", &N);
	rep (i, N)
		scanf("%lf", A + i);
	rep (i, N)
		scanf("%lf", B + i);
}

void Export(int T) {
	printf("Case #%d: %d %d\n", T, Ans1, Ans2);
}

void Solve1() {
	for (Ans1 = N; Ans1 > 0; -- Ans1) {
		bool Able = 1;//B[Ans1 - 1] < A[N - Ans1];
		for (int i = 0; i < Ans1; ++ i)
			Able &= (B[i] < A[N - Ans1 + i]);
		for (int i = 0; i < N - Ans1; ++ i)
			Able &= (A[i] < B[Ans1 + i]);
		if (Able)
			break;
	}
}

void Solve2() {
	Ans2 = N;
	for (int i = 0, j = 0; i < N; ++ i) {
		while (j < N && B[j] < A[i])
			++ j;
		if (j < N && B[j] > A[i]) {
			-- Ans2;
			++ j;
		}
	}
}

void Solve() {
	sort(A, A + N);
	sort(B, B + N);
	Solve1();
	Solve2();
}

int main() {
	int TestCase = 0;
	scanf("%d", &TestCase);
	for (int T = 1; T <= TestCase; ++ T) {
		Import();
		Solve();
		Export(T);
	}
}
