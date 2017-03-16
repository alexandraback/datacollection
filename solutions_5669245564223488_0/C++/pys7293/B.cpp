#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int N;

vector<string> S;

bool Chk[33];

bool Check(string x)
{
	memset(Chk, false, sizeof (Chk));
	for (int i = 0; i < x.size(); i++) {
		if ((i > 0 && x[i] != x[i - 1]) && Chk[x[i] - 'a']) return false;
		Chk[x[i] - 'a'] = true;
	}
	return true;
}

int main(void)
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int tt = 1; tt <= TC; tt++) {
		scanf("%d", &N);
		S.clear(); S.resize(N);
		for (int i = 0; i < N; i++) cin >> S[i];
		vector<int> P;
		for (int i = 0; i < N; i++) P.push_back(i);
		int F = 1;
		for (int i = 2; i <= N; i++) F *= i;
		int Ans = 0;
		for (int i = 0; i < F; i++) {
			string Cur = "";
			for (int j = 0; j < N; j++) Cur += S[P[j]];
			if (Check(Cur)) Ans++;
			next_permutation(P.begin(), P.end());
		}
		printf("Case #%d: %d\n", tt, Ans);
	}
	return 0;
}
