#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int MAXL = 110;
const int MAXN = 110;

string s[MAXN];
char buf[MAXL];
int n;
int p[MAXN];
int ch[30];

bool check_permutation() {
	memset(ch, -1, sizeof(ch));
	int pos = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < s[p[i]].size(); ++j, ++pos) {
			int cur_ch = s[p[i]][j] - 'a';
			if (ch[cur_ch] != -1 && pos - ch[cur_ch] > 1)
				return false;
			ch[cur_ch] = pos;				
		}
	}
	return true;
}

void solve(int test_id) {
	cout << "Case #" << test_id << ": ";
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		memset(buf, 0, sizeof(buf));
		scanf("%s", buf);
		s[i] = string(buf);
	}

	for (int i = 0; i < n; ++i)
		p[i] = i;

	int res = check_permutation();
	while (next_permutation(p, p + n)) {
		res += check_permutation();
	}

	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int test_id = 1; test_id <= t; ++test_id)
		solve(test_id);
	return 0;
}
