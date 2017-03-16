#define _CRT_SECURE_NO_WARNINGS // scanf(), gets() (needed for Visual C++)

#include <cassert>

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for (int i=0; i<(E); i++)

typedef long long ll;
//const ll MOD = 1000000007;
//const double PI = atan(1) * 4;






int N;
int p[1003];
vector<int> children[1003];

int cycleLength[1003];
bool visited[1003];

int calcHeight(int here) {
	int maxChildHeight = 0;
	for (int c : children[here])
		maxChildHeight = max(maxChildHeight, calcHeight(c));

	return 1+ maxChildHeight;
}



int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC; cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		printf("Case #%d: ", tc);

		FOR(i, 1003) children[i].clear();
		
		cin >> N;
		for (int i=1; i<=N; i++) {
			cin >> p[i];
			children[p[i]].push_back(i);
		}


		for (int i=1; i<=N; i++) {
			MEMSET(visited, 0);
			int v = i;
			int len = 0;
			while (visited[v] == false) {
				visited[v] = true;
				len++;
				v = p[v];
			}

			if (v == i)
				cycleLength[i] = len;
			else
				cycleLength[i] = 0;
		}



		int ans1 = 0;
		for (int i=1; i<=N; i++) if (cycleLength[i] == 2) {

			int maxChildHeight = 0;
			for (int c : children[i]) if (c != p[i]) {
				maxChildHeight = max(maxChildHeight, calcHeight(c));
			}

			ans1 += 1 + maxChildHeight;
		}





		int maxCycleLen = 0;
		for (int i=1; i<=N; i++)
			maxCycleLen = max(maxCycleLen, cycleLength[i]);


		int ans = max(ans1, maxCycleLen);
		cout << ans << endl;


	}


	return 0;
}
