#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
using namespace std;

int C, D, V;

static const int MAXV = 30;
bool B[MAXV + 1];
std::vector<int> coins;

void fillB(int val)
{
	for (int b = V; b >= 0; b--) {
		if (B[b]) {
			int s = b + val;
			if (s <= V) {
				B[s] = true;
			}
		}
	}
}

int solve()
{
	B[0] = true;
	for (int i = 0; i < coins.size(); i++) {
		fillB(coins[i]);
	}

	for (int result = 0; ; result++) {
		int b;
		for (b = 0; b <= V; b++) {
			if (!B[b]) break;
		}
		if (b == V + 1) {
			return result;
		}
		fillB(b);
	}
}

int main() {
#ifdef _DEBUG
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> C >> D >> V;
		fill(B, B + V + 1, false);
		coins.clear();
		for (int i = 0; i < D; i++) {
			int d;
			cin >> d;
			coins.push_back(d);
		}
		int result = solve();
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
