#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <sstream>
using namespace std;

#define MAXN 2505

int freq[MAXN];

int main(void) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, N, h;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		vector <int> ans;
		memset(freq, 0, sizeof(freq));

		for (int i = 0; i < (2*N-1)*N; i++) {
			cin >> h;
			freq[h]++;
		}

		cout << "Case #" << t << ":";
		for (int i = 0; i < MAXN; i++) {
			if (freq[i] & 1) {
				cout << ' ' << i;
			}
		}
		cout << '\n';
	}
	return 0;
}
