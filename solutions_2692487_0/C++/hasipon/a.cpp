#include <iostream>
#include <vector>
#include <map>
using namespace std;
int A, N;
vector<int> a;
map<pair<int,int>, int> memo;
int f(int x, int y) {
	if (memo.count(make_pair(x, y))) return memo[make_pair(x, y)];
	for (;;) {
		bool f = true;
		for (int i = 0; i < N; ++ i) if ((y>>i)&1) {
			if (a[i] < x) {
				x += a[i];
				y ^= 1<<i;
				f = false;
			}
		}
		if (f) break;
	}
	if (y == 0) return memo[make_pair(x, y)] = 0;
	if (x == 1) return memo[make_pair(x, y)] = 1<<29;
	return memo[make_pair(x, y)] = f(2*x-1, y) + 1;
}
int solve() {
	cin >> A >> N;
	a = vector<int>(N);
	for (int i = 0; i < N; ++ i) cin >> a[i];
	memo.clear();
	int r = 1<<30;
	for (int p = 0; p < (1<<N); ++ p) {
		r = min(r, f(A, p) + N - __builtin_popcount(p));
	}
	return r;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
