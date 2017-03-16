#include <algorithm>
#include <cmath>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int MOD = 1000000007;

int N;
int L[33], R[33], M[33];

vector<string> S;

long long Fact(int x)
{
	long long Ret = 1;
	for (int i = 2; i <= x; i++) (Ret *= i) %= MOD;
	return Ret;
}

int main(void)
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	for (int tt = 1; tt <= TC; tt++) {
		printf("Case #%d: ", tt);
		scanf("%d", &N);
		S.clear(); S.resize(N);
		bool F = true;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			S[i].erase(unique(S[i].begin(), S[i].end()), S[i].end());
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (S[i].size() > 1 && S[j].size() > 1) {
					if (S[i][0] == S[j][S[j].size() - 1] && S[j][0] == S[i][S[i].size() - 1]) {
						F = false;
						break;
					}
				}
				for (int k = 1; k + 1 < S[i].size(); k++) {
					for (int l = 0; l < S[j].size(); l++) {
						if (i == j && k == l) continue;
						if (S[i][k] == S[j][l]) {
							F = false;
							break;
						}
					}
				}
			}
		}
		if (!F) {
			printf("0\n");
			continue;
		}
		memset(L, -1, sizeof (L));
		memset(R, -1, sizeof (R));
		memset(M, 0, sizeof (M));
		for (int i = 0; i < N; i++) {
			if (S[i][0] != S[i][S[i].size() - 1]) {
				if (L[S[i][S[i].size() - 1] - 'a'] == -1) L[S[i][S[i].size() - 1] - 'a'] = i;
				else {
					F = false;
					break;
				}
				if (R[S[i][0] - 'a'] == -1) R[S[i][0] - 'a'] = i;
				else {
					F = false;
					break;
				}
			} else M[S[i][0] - 'a']++;
		}
		if (!F) {
			printf("0\n");
			continue;
		}
		long long Ans = 1;
		int Cnt = 0;
		for (int i = 0; i < 26; i++) {
			(Ans *= Fact(M[i])) %= MOD;
			if (L[i] == -1 && R[i] == -1 && M[i] > 0) Cnt += 2;
			if (L[i] != -1 && R[i] != -1) L[i] = R[i] = -1;
		}
		for (int i = 0; i < 26; i++) if (L[i] != -1 || R[i] != -1) Cnt++;
		(Ans *= Fact(Cnt >> 1)) %= MOD;
		printf("%lld\n", Ans);
	}

	return 0;
}
