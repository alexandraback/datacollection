#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Int64;

const int maxn = 100000;

Int64 v[maxn];
int N;
Int64 E, R;

Int64 Cut(Int64 a) {
	return a > E ? E : a;
}

Int64 Fill(Int64 a) {
	return a < 0 ? 0 : a;
}

Int64 Arrange(int head, int tail, Int64 startAmount, Int64 endLimit) { // No saving mode
	if (head >= tail) return 0;
	if (startAmount > E) startAmount = E;
	if (startAmount < 0) startAmount = 0;
	int index = head;
	for (int i = head + 1; i < tail; i++)
		if (v[i] > v[index]) index = i;
	// How much can get from before
	Int64 upperBound = Cut(startAmount + (index - head) * R);
	Int64 lowerBound = Fill(endLimit - (tail - index) * R);
	Int64 value = (upperBound - lowerBound) * v[index];
	Int64 left = Arrange(head, index, startAmount, upperBound);
	Int64 right = Arrange(index + 1, tail, lowerBound + R, endLimit);
	return left + value + right;
}

void Solve() {
	cin >> E >> R >> N;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	Int64 ans = Arrange(0, N, E, 0);
	cout << ans << endl;
}

int main() {
	int t, i;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		Solve();
	}
	return 0;
}
