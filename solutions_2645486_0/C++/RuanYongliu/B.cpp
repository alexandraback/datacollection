#include <map>
#include <iostream>
using namespace std;

const int N = 10000 + 10;

long long e, r, v[N]; 
int n;
map<long long, long long> f[N];

long long dfs(int i, long long R) {
	if (i == n) {
		return 0;
	}
	if (f[i].find(R) != f[i].end()) {
		return f[i][R];
	}
	long long result = dfs(i + 1, min(e, R + r));
	for (long long u = 1; u <= e && u <= R; ++u) {
		result = max(result, dfs(i + 1, min(e, R - u + r)) + u * v[i]);
	}
	//if (r <= R) {
	//	result = max(result, dfs(i + 1, R) + static_cast<long long>(r) * v[i]);
	//}
	//if (e <= R) {
	//	result = max(result, dfs(i + 1, R - e + r) + static_cast<long long>(e) * v[i]);
	//}
	//if (R <= e) {
	//	result = max(result, dfs(i + 1, r) + static_cast<long long>(R) * v[i]);
	//}
	f[i][R] = result;
	return result;
}

int main() {
	int T, cas = 0;
	for (cin >> T; T; --T) {
		cin >> e >> r >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			f[i].clear();
		}
		long long ans = dfs(0, e);
		cout << "Case #" << ++cas << ": " << ans << "\n";
	}
	return 0;
}
