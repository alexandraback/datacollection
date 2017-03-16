#include <iostream>
using namespace std;

int T;
int ans;
int E, R, N;
int v[11];
void r(int val, int energy, int cur) {
	if(cur == N) {
		ans = max(ans, val);
	} else {
		for(int i = 0; i <= energy; ++i) {
			r(val + v[cur] * i, min(energy - i + R, E), cur + 1);
		}
	}
}
int main() {
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		ans = 0;
		cin >> E >> R >> N;
		for(int j = 0; j < N; ++j) {
			cin >> v[j];
		}
		r(0, E, 0);
		cout << ans << endl;
	}
	return 0;
}