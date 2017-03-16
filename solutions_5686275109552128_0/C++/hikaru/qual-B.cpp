#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;
deque<pair<bool, int>> P;

int solve()
{
	int maxi = (int) P.size() - 1;
	for (int i = 0; i < P.size(); i++) {
		if (P[i].first && P[i].second > P[maxi].second) {
			maxi = i;
		}
	}
	
	const int value = P[maxi].second;
	int result = value;
	P[maxi].first = false;

	for (int n = 2; n <= (value + 1) / 2; n++) {
		int v = value;
		for (int i = 0; i < n; i++) {
			P.push_back(make_pair(true, min(v, (value + n - 1) / n)));
			v -= (value + n - 1) / n;
		}
		result = min(result, solve() + (n - 1));
		for (int i = 0; i < n; i++) {
			P.pop_back();
		}
	}

	P[maxi].first = true;
	return result;
}

int main(int argc, char* argv[])
{
	if (argc > 1) {
		FILE* fp;
		freopen_s(&fp, argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int D;
		cin >> D;
		P.clear();
		for (int i = 0; i < D; i++) {
			int n;
			cin >> n;
			P.push_back(make_pair(true, n));
		}

		cout << "Case #" << t << ": " << solve() << endl;
	}

	return 0;
}
