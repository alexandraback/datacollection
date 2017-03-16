#include <iostream>
#include <algorithm>

using namespace std;

int E, R, N, v[20], ans;

void go(int i, int e, int sum)
{
	if (i >= N) {
		ans = max(ans, sum);
		return;
	}
	for (int k = 0; k <= e; k++)
		go(i + 1, min(E, e - k + R), sum + k * v[i]);
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cin >> E >> R >> N;
		for (int i = 0; i < N; i++) cin >> v[i];
		ans = 0;
		go(0, E, 0);
		cout << "Case #" << ti << ": " << ans << endl;
	}

	return 0;
}
