#include <iostream>
#include <algorithm>

using namespace std;

typedef long long Int64;

const int maxn = 10000;

Int64 products[maxn];
int sum[maxn];
int R, N, M, K;

int Count(Int64 product, int factor) {
	int ans = 0;
	while (product > 1 && product % factor == 0) {
		ans++;
		product /= factor;
	}
	return ans;
}

bool Check() {
	for (int i = 0; i < K; i++) {
		if (Count(products[i], 3) > sum[3]) return false;
		if (Count(products[i], 5) > sum[5]) return false;
		int sum2 = Count(products[i], 2);
		if (sum2 / 2 >= sum[4]) sum2 -= sum[4] * 2;
		else sum2 &= 1;
		if (sum2 > sum[2]) return false;
	}
	for (int i = 2; i <= 5; i++)
		for (int j = 0; j < sum[i]; j++)
			cout << i;
	cout << endl;
	return true;
}

bool DFS(int dig, int left) {
	if (dig == M) {
		sum[dig] = left;
		return Check();
	}
	for (int i = 0; i <= left; i++) {
		sum[dig] = i;
		if (DFS(dig + 1, left - i)) return true;
	}
	return false;
}

void Solve() {
	cin >> R >> N >> M >> K;
	for (int t = 0; t < R; t++) {
		for (int i = 0; i < K; i++)
			cin >> products[i];
		DFS(2, N);
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":" << endl;
		Solve();
	}
	return 0;
}
