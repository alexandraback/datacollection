#include <iostream>
using namespace std;

const int MAX_D = 1005;
long long p[MAX_D] = {};
const long long INF = 10005000000;

long long count_lifts(long long food, long long eat_time) {
	long long ans = 0;
	ans += food / eat_time;
	if ((food % eat_time) != 0) {
		++ans;
	}
	return (ans - 1);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int D;
		cin >> D;
		long long max_p = 0;
		for (int i = 0; i < D; ++i) {
			cin >> p[i];
			max_p = max(p[i], max_p);
		}
		long long ans = INF;
		for (long long eat_time = 1; eat_time <= max_p; ++eat_time) {
			long long lifts = 0;
			for (int i = 0; i < D; ++i) {
				lifts += count_lifts(p[i], eat_time);
			}
			ans = min(ans, eat_time + lifts);
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}