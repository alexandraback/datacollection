#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<double> a(N), b(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int pointsa = 0;
	int j = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] > b[j]) {
			++j;
			++pointsa;
		}
	}

	int pointsb = 0;
	j = N-1;
	for (int i = N; i --> 0; ) {
		if (a[i] > b[j])
			++pointsb;
		else
			--j;
	}

	cout << pointsa << ' ' << pointsb << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
