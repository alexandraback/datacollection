#include <iostream>
#include <vector>
#include <map>
using namespace std;
int E, R, N;
vector<int> v;
map<pair<int,int>, int> memo;
int f(int p, int e) {
	if (p == N) return 0;
	if (memo.count(make_pair(p, e))) return memo[make_pair(p, e)];
	int r = 0;
	for (int i = 0; i <= e; ++ i) {
		r = max(r, f(p+1, min(E, e-i+R)) + i * v[p]);
	}
	return memo[make_pair(p, e)] = r;
}
int solve() {
	cin >> E >> R >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; ++ i) cin >> v[i];
	memo.clear();
	return f(0, E);
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
