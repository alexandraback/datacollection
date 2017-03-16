#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T;
long long c, n;
vector<long long> a;

void init() {
	cin >> c >> n;
	a.clear();
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		a.push_back(x);
	}
}

int work() {
	sort(a.begin(), a.end());
	long long best = n;
	if (c == 1)
		return best;
	long long cnt = 0;
	for (int i=0; i < n; i++) {
		best = min(n - i + cnt, best);
		while (c <= a[i]) {
			cnt++;
			c += (c-1);
		}
		c += a[i];
	}
	if (cnt < best)
		best = cnt;
	return best;
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		cout << "Case #" << i << ": " << work() << endl;
	}
	return 0;
}