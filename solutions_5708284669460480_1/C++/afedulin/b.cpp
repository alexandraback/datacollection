#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>

using namespace std;
int K, L, S;
string alphas, target;
int prf[110];
int phi[110][26];
int has_char[26];
long double dp_prob[110][110];
int dp_max[110][110];
int used;
int was_max[110][110];
int was_prob[110][110];
long double prob[26];

long double f_prob(int length, int state) {
	long double& res = dp_prob[length][state];
	if (length == S) {
		return 0;
	}
	if (was_prob[length][state] == used) return res;
	was_prob[length][state] = used;
	res = 0;
	int nstate;
	for (int c = 0; c < 26; c++) {
		if (has_char[c]) {
			nstate = phi[state][c];
			res += prob[c] * (f_prob(length + 1, nstate) + (nstate == L ? 1 : 0));
		}
	}
	return res;
}

int f_max(int length, int state) {
	int& res = dp_max[length][state];
	if (length == S) {
		return 0;
	}
	if (was_max[length][state] == used) return res;
	was_max[length][state] = used;
	res = 0;
	int nstate;
	for (int c = 0; c < 26; c++) {
		if (has_char[c]) {
			nstate = phi[state][c];
			res = max(res, f_max(length + 1, nstate) + (nstate == L ? 1 : 0));
		}
	}
	//cerr << "lengt " << length << " state " << state << " res " << res << "\n";
	return res;
}

long double solve() {
	assert((int)alphas.size() == K);
	assert((int)target.size() == L);
	for (int k = 0, i = 2; i <= (int)target.size(); i++) {
		while (k > 0 && target[i - 1] != target[k]) k = prf[k];
		if (target[i - 1] == target[k]) {
			k++;
		}
		prf[i] = k;
	}

	for (int i = 0; i <= (int)target.size(); i++) {
		for (int c = 0; c < 26; c++) {
			int t = i;
			while (t && target[t] - 'A' != c) t = prf[t];
			if (target[t] - 'A' == c) {
				phi[i][c] = t + 1;
			} else {
				phi[i][c] = 0;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		prob[i] = 0;
		has_char[i] = 0;
	}

	for (int i = 0; i < K; i++) {
		prob[alphas[i] - 'A'] += 1;
		has_char[alphas[i] - 'A'] = true;
	}

	for (int i = 0; i < 26; i++) {
		prob[i] /= K;
	}

	used++;
	return f_max(0, 0) - f_prob(0, 0);
}

int main() {
	int T, tn = 0;
	cin >> T;
	while (T --> 0) {
		tn++;
		cerr << "Case #" << tn << "\n";
		cin >> K >> L >> S;
		cin >> alphas;
		cin >> target;
		long double res = solve();
		cout << "Case #" << tn << ": " << setprecision(10) << fixed << res << "\n";
	}
}