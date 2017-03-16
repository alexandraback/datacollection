#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

void solve(int tcase) {
	cout << "Case #" << tcase << ": ";

	int n;
	cin >> n;

	vector<int> nxt(n);

	for (int i = 0; i < n; ++i) {
		cin >> nxt[i];
		--nxt[i];
	}

	vector<int> cyclelen(n, -1);
	vector<int> gowhere(n, -1);
	vector<int> gowherelen(n, -1);

	int mcycle = 0;

	for (int i = 0; i < n; ++i) {
		vector<int> used(n, -1);
		int cur = i;
		int ps = 0;

		vector<int> st;

		while (true) {
			if (used[cur] != -1) {
				int len = ps - used[cur];
				mcycle = max(mcycle, len);
				for (int i = used[cur]; i < ps; ++i) {
					cyclelen[st[i]] = len;
					gowhere[st[i]] = -1;
					gowherelen[st[i]] = -1;
				}

				for (int i = 0; i < used[cur]; ++i) {
					cyclelen[st[i]] = -1;
					gowhere[st[i]] = cur;
					gowherelen[st[i]] = used[cur] - i;
				}
				break;
			}
			st.push_back(cur);
			used[cur] = ps;
			cur = nxt[cur];
			++ps;
		}
	}

	vector<int> tcycle;
	vector<int> used(n, 0);
	for (int i = 0; i < n; ++i) {
		if (!used[i] && nxt[nxt[i]] == i) {
			tcycle.push_back(i);
			used[i] = 1;
			used[nxt[i]] = 1;
		}
	}

	int res2 = 0;
	for (int i = 0; i < tcycle.size(); ++i) {
		int id1 = tcycle[i];
		int id2 = nxt[id1];

		int mx1 = 0;
		int mx2 = 0;

		for (int j = 0; j < n; ++j) {
			if (gowhere[j] == id1) {
				mx1 = max(mx1, gowherelen[j]);
			}
			if (gowhere[j] == id2) {
				mx2 = max(mx2, gowherelen[j]);
			}
		}
		res2 += 2 + mx1 + mx2;
	}

	cout << max(mcycle, res2) << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cerr << i << endl;
		solve(i + 1);
	}

	return 0;
}