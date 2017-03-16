#include <bits/stdc++.h>
using namespace std;

int run() {
	int _, a, b, c;
	cin >> _;
	for (int cas = 1; cas <= _; ++cas) {
		cin >> a >> b >> c;
		int answer = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) answer += (i & j) < c;
		}
		cout << "Case #" << cas << ": " << answer << endl;
	}
	return 0;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	ios::sync_with_stdio(0);
	return run();
}
