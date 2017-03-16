#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

string keyboard, s;

const int NMAX = 10010;

int cnt[27];
double prob[27];
double DP[102][102][102];
double ans ;
int K, L, S, maxbanana = 0;


int count(string temp) {
	int ret = 0;
	for (int i = 0; i <= temp.size() - s.size(); i++) {
		int flag = 1;
		for (int j = 0; j < s.size(); j++)
			if (temp[i + j] != s[j])
				flag = 0;
		ret += flag;
	}
	if (ret > maxbanana)
		maxbanana = ret;
	return ret;
}

void DFS(string cur, double p) {
	if (cur.size() == S) {
		ans += p * count(cur);
		return;
	}
	for (char c = 'A'; c <= 'Z'; c++) 
		if (prob[c-'A'] > 0) {
		string next = cur;
		next += c;
		DFS(next, p * prob[c - 'A']);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> K >> L >> S;
		ans = 0.;
		maxbanana = 0.;

		cin >> keyboard;
		cin >> s;
		for (int i = 0; i < 26; i++) {
			prob[i] = 0.;
			cnt[i] = 0;
		}

		for (int i = 0; i < keyboard.size(); i++)
			cnt[keyboard[i] - 'A']++;

		for (int i = 0; i < 26; i++)
			prob[i] = (1.*cnt[i]) / keyboard.size();

		string cur = "";
		DFS(cur, 1.);

	/*	memset(DP, 0, sizeof(DP));
		DP[0][0][0] = 1.;

		int pref = 0;
		for (int i = 0; i < L-1; i++) {
			bool flag = 1;
			for (int k = L - i - 1; k < L; k++)
				if (s[k] != s[k - (L - i - 1)]) {
					flag = 0;
					break;
				}
			if (flag)
				pref = i;
		}

		for (int i = 0; i < S; i++)
			for (int k = 0; k < L; k++)
				for (int cnt = 0; cnt < S; cnt++)
					if (DP[i][k][cnt]) {
						for (int c = 0; c < 26; c++)
							if (prob[c] > 0) {
								if (s[k] == c) {

								}
							}
					}
		double ans = 0.;
		for (int i = 0; i <= L; i++)
			for (int j = 0; j <= S; j++)
				ans += DP[L][i][j] * j;
				*/
		cout << "Case #" << test << ": " ;
		printf("%.7f\n", maxbanana - ans);
	}

	return 0;
}