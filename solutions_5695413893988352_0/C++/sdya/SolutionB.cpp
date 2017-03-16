#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <bitset>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

bool apply(const string& s, const string& t) {
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '?') {
			continue;
		}
		if (s[i] != t[i]) {
			return false;
		}
	}
	return true;
}

long long stringToVal(string s) {
	long long res = 0;
	for (int i = 0; i < s.size(); ++i) {
		res *= 10LL;
		res += s[i] - '0';
	}
	return res;
}

pair<long long, pair<string, string>> solve_real_min(string S, string T) {
	int len = S.length();

	int eq = true;
	for (int i = 0; i < len; ++i) {
		if (S[i] == T[i]) {
			if (S[i] == '?') {
				S[i] = '0', T[i] = '0';
			}
		} else if (S[i] == '?') {
			S[i] = T[i];
		} else if (T[i] == '?') {
			T[i] = S[i];
		} else {
			if (S[i] > T[i]) {
				for (int j = i; j < len; ++j) {
					if (S[j] == '?') S[j] = '0';
					if (T[j] == '?') T[j] = '9';
				}
				return make_pair(stringToVal(S) - stringToVal(T), make_pair(S, T));
			} else {
				for (int j = i; j < len; ++j) {
					if (S[j] == '?') S[j] = '0';
					if (T[j] == '?') T[j] = '0';
				}
				return make_pair(stringToVal(S) - stringToVal(T), make_pair(S, T));
			}
		}
	}

	return make_pair(stringToVal(S) - stringToVal(T), make_pair(S, T));
}

pair<pair<long long, pair<string, string>>,
	pair<long long, pair<string, string>>>
	solve_min(string S, string T) {
	pair<long long, pair<string, string>> cur1 = solve_real_min(T, S);
	cur1.first = -cur1.first;
	swap(cur1.second.first, cur1.second.second);
	pair<long long, pair<string, string>> cur2 = solve_real_min(S, T);
	return make_pair(cur1, cur2);
}



pair<long long, pair<string, string>> solve_real_max(string S, string T) {
	int len = S.length();

	int eq = true;
	for (int i = 0; i < len; ++i) {
		if (S[i] == '?') {
			S[i] = '9';
		}
		if (T[i] == '?') {
			T[i] = '0';
		}
	}

	return make_pair(stringToVal(S) - stringToVal(T), make_pair(S, T));
}

pair<pair<long long, pair<string, string>>,
	pair<long long, pair<string, string>>>
	solve_max(string S, string T) {
	pair<long long, pair<string, string>> cur1 = solve_real_max(T, S);
	cur1.first = -cur1.first;
	swap(cur1.second.first, cur1.second.second);
	pair<long long, pair<string, string>> cur2 = solve_real_max(S, T);
	return make_pair(cur1, cur2);
}

pair<string, string> solveMy(string S, string T) {
	int len = S.length();

	string add = "";
	for (int i = 0; i < len; ++i) {
		if (S[i] == T[i]) {
			if (S[i] == '?') {
				S[i] = '0';
				T[i] = '0';
			}
			add += S[i];
		} else if (S[i] == '?') {
			S[i] = T[i];
			add += S[i];
		} else if (T[i] == '?') {
			T[i] = S[i];
			add += T[i];
		} else {
			break;
		}
	}

	string nS, nT;
	for (int i = add.length(); i < S.length(); ++i) {
		nS += S[i];
		nT += T[i];
	}

	S = nS;
	T = nT;
	len = S.length();

	if (len == 1) {
		int mn = 100;
		int ti = -1;
		int tj = -1;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				string s1 = ""; s1 += i + '0';
				string s2 = ""; s2 += j + '0';

				if (apply(S, s1) && apply(T, s2)) {
					int diff = abs(i - j);
					if (diff < mn) {
						mn = diff;
						ti = i, tj = j;
					} else if (diff == mn) {
						if (make_pair(i, j) < make_pair(ti, tj)) {
							ti = i;
							tj = j;
						}
					}
				}
			}
		}
		string addS = add, addT = add;
		addS += ti + '0';
		addT += tj + '0';
		return make_pair(addS, addT);
	} else if (len == 0) {
		return make_pair(add, add);
	}

	int fpart = (len + 1) / 2;

	string S1, T1;
	for (int i = 0; i < fpart; ++i) {
		S1 += S[i];
		T1 += T[i];
	}

	string S2, T2;
	for (int i = fpart; i < len; ++i) {
		S2 += S[i];
		T2 += T[i];
	}

	pair<pair<long long, pair<string, string>>,
		pair<long long, pair<string, string>>> mins = solve_min(S1, T1);
	pair<pair<long long, pair<string, string>>,
		pair<long long, pair<string, string>>> mins2 = solve_max(S2, T2);

	long long pw = 1;
	for (int i = 0; i < len - fpart; ++i) {
		pw *= 10LL;
	}

	long long res1 = mins.first.first * pw + mins2.second.first;
	pair<string, string> ret1 = make_pair(mins.first.second.first + mins2.second.second.first,
		mins.first.second.second + mins2.second.second.second);
	long long res2 = mins.second.first * pw + mins2.first.first;
	pair<string, string> ret2 = make_pair(mins.second.second.first + mins2.first.second.first,
		mins.second.second.second + mins2.first.second.second);

	if (res1 < 0) res1 = -res1;
	if (res2 < 0) res2 = -res2;

	if (res1 < res2) {
		return make_pair(add + ret1.first, add + ret1.second);
	}
	if (res2 < res1) {
		return make_pair(add + ret2.first, add + ret2.second);
	}
	pair<string, string> ans = min(ret1, ret2);
	return make_pair(add + ans.first, add + ans.second);
}

string valToString(long long x, int len) {
	string res = "";
	while (x > 0) {
		res += x % 10 + '0';
		x /= 10;
	}
	while (res.size() < len) res += '0';
	reverse(res.begin(), res.end());
	return res;
}

pair<string, string> solveBrut(string S, string T) {
	int len = S.length();

	string cur = "";
	for (int i = 0; i < len; ++i) cur += '9';

	long long lim = stringToVal(cur);

	int mn = 100000000;
	int ti = -1;
	int tj = -1;

	for (int i = 0; i <= lim; ++i) {
		if (!apply(S, valToString(i, len))) {
			continue;
		}
		for (int j = 0; j <= lim; ++j) {
			if (!apply(T, valToString(j, len))) {
				continue;
			}

			int bs = abs(i - j);
			if (bs < mn) {
				mn = bs;
				ti = i;
				tj = j;
			} else if (bs == mn) {
				if (make_pair(i, j) < make_pair(ti, tj)) {
					ti = i;
					tj = j;
				}
			}
		}
	}
	return make_pair(valToString(ti, len), valToString(tj, len));
}

string genRand(int len) {
	string cur = "";
	for (int i = 0; i < len; ++i) {
		if (rand() % 2 == 0) cur += '?'; else
			cur += rand() % 10 + '0';
	}
	return cur;
}

void solve(int tcase) {
	printf("Case #%d: ", tcase);

	string S, T;
	cin >> S >> T;

	pair<string, string> ans = solveBrut(S, T);
	//pair<string, string> brut = solveBrut(S, T);

	/*if (ans != brut) {
		cerr << S << " " << T << endl;
		cerr << ans.first << " " << ans.second << endl;
		cerr << brut.first << " " << brut.second << endl;
		return;
	} else {
		cerr << "OK" << endl;
	}*/

	cout << ans.first << " " << ans.second << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		solve(i + 1);
	}

	/*while (true) {
		int len = rand() % 4 + 1;
		string cur1 = genRand(len);
		string cur2 = genRand(len);

		pair<string, string> ans1 = solveMy(cur1, cur2);
		pair<string, string> ans2 = solveBrut(cur1, cur2);

		if (ans1 != ans2) {
			cout << cur1 << " " << cur2 << endl;
			cout << ans1.first << " " << ans1.second << endl;
			cout << ans2.first << " " << ans2.second << endl;
			return 0;
		} else {
			cout << "OK " << cur1 << " " << cur2 << endl;
		}
	}*/

	return 0;
}
