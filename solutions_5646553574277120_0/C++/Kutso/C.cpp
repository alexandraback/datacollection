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

int best, DP[500];
const int NMAX = 10010;
vector <int> coins;


bool done(int v) {
	for (int i = 0; i <= v; i++)
		if (!DP[i])
			return false;
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		best = 5;
		int c, d, v;
		cin >> c >> d >> v;
		memset(DP, 0, sizeof(DP));
		coins.clear();
		for (int i = 0; i < d; i++) {
			int a;
			cin >> a;
			coins.push_back(a);
		}

		DP[0] = 1;
		for (int j = 0; j < coins.size(); j++)
			for (int i = v; i >= 0; i--)
				if (DP[i] && i + coins[j] <= v)
					DP[i + coins[j]] = 1;
		best = 0;
		while (!done(v)) {
			best++;
			for (int j = 0; j<= v; j++)
				if (!DP[j]) {
					coins.push_back(j);
					break;
				}

			for (int i = v; i >= 0; i--)
				if (DP[i] && i + coins[coins.size()-1] <= v)
					DP[i + coins[coins.size() - 1]] = 1;
		}
		cout << "Case #" << test << ": " << best << endl;
	}

	return 0;
}