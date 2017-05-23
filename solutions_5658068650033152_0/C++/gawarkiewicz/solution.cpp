#include <iostream>
#include <stack>

using namespace std;

int brut(int N, int M, int K) {
	auto ok = [&](int x, int y) {
		if (x < 0 || y < 0 || x == M || y == N) return false;
		return true;
	};
	auto m = [&](int b, int x, int y) {
		return (b >> (M*y + x)) & 1;
	};
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, -1, 0, 1 };
	int ret = N*M;

	for (int b = 0; b < (1 << (N*M)); ++b) {
		stack<pair<int, int>> st;
		for (int i = 0; i < M; ++i) if (0 == m(b, i, 0)) st.push(make_pair(i, 0));
		for (int i = 0; i < M; ++i) if (0 == m(b, i, N - 1)) st.push(make_pair(i, N - 1));
		for (int i = 0; i < N; ++i) if (0 == m(b, 0, i)) st.push(make_pair(0, i));
		for (int i = 0; i < N; ++i) if (0 == m(b, M - 1, i)) st.push(make_pair(M - 1, i));
		int enclosed = (1 << N*M) - 1;
		while (!st.empty()) {
			pair<int, int> t = st.top();
			st.pop();
			if (m(enclosed, t.first, t.second) == 0) continue;
			enclosed &= ~(1 << (M*t.second + t.first));
			for (int i = 0; i < 4; ++i) {
				if (m(enclosed, t.first + dx[i], t.second + dy[i]) == 0) continue;
				if (m(b, t.first + dx[i], t.second + dy[i]) == 1) continue;
				st.push(make_pair(t.first + dx[i], t.second + dy[i]));
			}
		}
		{
			int cur = 0;
			for (int i = 0, bb = enclosed; i < N*M; ++i) {
				cur += bb & 1;
				bb /= 2;
			}
			if (cur < K) continue;
		}
		{
			int cur = 0;
			for (int i = 0, bb = b; i < N*M; ++i) {
				cur += bb & 1;
				bb /= 2;
			}
			if (cur < ret) ret = cur;
		}
	}
	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int q = 1; q <= T; ++q) {
		int N, M, K;
		cin >> N >> M >> K;
		int ans = brut(N, M, K);
		cout << "Case #" << q << ": " << ans << endl;
	}
	return 0;
}