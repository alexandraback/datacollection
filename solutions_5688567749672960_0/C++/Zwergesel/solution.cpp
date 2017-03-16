#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull steps[10000001];

ull flip(ull x) {
	ull y = 0;
	while (x) {
		y = y * 10 + (x % 10);
		x /= 10;
	}
	return y;
}

void solve()
{
	ull n;
	cin >> n;
	cout << steps[n];
}

void prepare()
{
	fill_n(steps, 10000001, 1ULL << 62);
	queue<ull> q;
	q.push(1);
	steps[1] = 1;
	while (!q.empty()) {
		ull x = q.front(); q.pop();
		ull y = flip(x);
		if (steps[x] + 1 < steps[x+1]) {
			steps[x+1] = steps[x] + 1;
			q.push(x+1);
		}
		if (steps[x] + 1 < steps[y]) {
			steps[y] = steps[x] + 1;
			q.push(y);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	prepare();
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
