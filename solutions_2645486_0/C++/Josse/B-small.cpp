#include <iostream>
#include <cassert>

using namespace std;

int E, R, N;
int best;
int v[10];

void dfs(int d, int cur, int som) {
	if (d == N) {
		if (som > best) best = som;
		return;
	}
	for (int i = 0; i <= cur; i++) {
		dfs(d + 1, min(E, cur - i + R), som + i * v[d]);
	}
}

void solve(int casenum) {
	cin >> E >> R >> N;
	for (int i = 0; i < N; i++) cin >> v[i];
	best = -1;
	dfs(0, E, 0);
	cout << "Case #" << casenum << ": " << best << endl;
}

int main() {
	int T;
	cin >> T;
	assert(T > 0 && T <= 1000); 
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
