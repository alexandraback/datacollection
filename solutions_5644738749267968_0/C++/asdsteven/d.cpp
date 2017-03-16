#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
	int N;
	cin >> N;
	double a[N], b[N];
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	sort(a, a + N);
	sort(b, b + N);
	int r = N - 1;
	for (int i = N - 1; i >= 0; --i)
		if (b[i] < a[r]) 
			--r;
	cout << N - r - 1 << ' ';
	r = 0;
	for (int i = 0; i < N; ++i) {
		while (r < N && a[i] > b[r])
			++r;
		if (r == N) {
			cout << N - i << endl;
			return;
		}
		++r;
	}
	cout << 0 << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
}
