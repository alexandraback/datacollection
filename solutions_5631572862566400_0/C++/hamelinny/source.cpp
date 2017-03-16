#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int bff[1005];
int num[1005];
bool check[1005];
int mxmx[1005];

int main() {

	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.txt", "w", stdout);

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;

		for (int j = 0; j < n; j++) {
			num[j] = 0;
			check[j] = false;
			mxmx[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			cin >> bff[j];
			bff[j]--;
		}
		for (int j = 0; j < n; j++) {
			if (bff[bff[j]] == j)
				check[j] = true;
		}
		int cycle = 0;
		for (int j = 0; j < n; j++) {
			int cur = j;
			vector <int> cc;
			cc.push_back(cur);
			num[cur] = 1;

			//islst[cur] = true;
			while (!num[bff[cur]]) {
				num[bff[cur]] = num[cur] + 1;
				cur = bff[cur];
				cc.push_back(cur);
			}
			if (bff[bff[cur]] == cur) {
				mxmx[cur] = max(mxmx[cur], num[cur]);
			}
			else {
				cycle = max(cycle, num[cur] - num[bff[cur]] + 1);
			}

			for (int i = 0; i < cc.size(); i++)
				num[cc[i]] = 0;
		}
		int sm = 0;
		for (int j = 0; j < n; j++) {
			if (check[j])
				sm += mxmx[j] - 1;
		}
		cout << "Case #" << i << ": " << max(sm, cycle) << '\n';
	}

}