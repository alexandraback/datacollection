#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

string s[1000];
bool sb[1000][26] = { false };
bool isV[1000] = { true };
int n;
int cnt = 0;

bool marked[1000] = { false };
int p[1000] = { 0 };

void solve(int cur, bool sb_[26]) {
	if (cur == n) {
		cnt++;
		/*
		for (int i = 0; i < n; i++) {
			printf("%d ", p[i]);
		}
		printf("\n");
		*/
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!marked[i]) {
				int c = 0;
				for (int j = 0; j < 26; j++) {
					if (sb_[j] && sb[i][j]) {
						c++;
					}
				}
				if (c > 1) {
					continue;
				}
				else {
					if (c == 1) {
						if (cur == 0) {
							continue;
						}
						else {
							if (s[i][0] != s[p[cur - 1]][s[p[cur - 1]].length() - 1]) {
								continue;
							}
						}
					}

					marked[i] = true;
					p[cur] = i;

					bool newSb[26] = { false };

					for (int j = 0; j < 26; j++) {
						newSb[j] = sb_[j] || sb[i][j];
					}

					solve(cur + 1, newSb);

					p[cur] = -1;
					marked[i] = false;
				}
			}
		}
	}
}


int main() {
	int T;
	
	scanf("%d", &T);
	int o = 0;
	while (T > 0) {
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			marked[i] = false;
			p[i] = -1;
			isV[i] = true;
			for (int j = 0; j < 26; j++) {
				sb[i][j] = false;
			}
			cnt = 0;
		}

		bool f = true;

		for (int i = 0; i < n; i++) {
			cin >> s[i];

			sb[i][s[i][0] - 'a'] = true;

			for (int j = 1; j < s[i].length(); j++) {
				if (s[i][j - 1] != s[i][j]) {
					if (sb[i][s[i][j] - 'a']) {
						isV[i] = false;
						f = false;
					}
					else {
						sb[i][s[i][j] - 'a'] = true;
					}
				}
			}
		}



		o++;
		printf("Case #%d: ", o);

		if (!f) {
			printf("0\n");
		}
		else {
			bool sb[26] = { false };
			solve(0, sb);
			printf("%d\n", cnt);
		}

		



		T--;
	}
	return 0;
}