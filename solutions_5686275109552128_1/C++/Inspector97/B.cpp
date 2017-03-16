#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#pragma warning (disable : 4996)

vector<int> v;

bool check2(int m, int k) {
	int need = 0;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (v[i] > m) {
			need += v[i] / m;
			if (v[i] % m == 0)
				need--;
		}
	}
	return need <= k;
}

bool check(int k) {
	for (int t = 0; t < k; t++) {
		if (check2(k - t, t))
			return true;
	}
	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int K, KK = 0;
	cin >> K;
	while (K-- && ++KK) {
		cout << "Case #" << KK << ": ";
		int n;
		cin >> n;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (v[0] == 1) {
			n = n;
		}
		int mm = 0;
		for (int i = 0; i < n; i++) {
			mm = max(mm, v[i]);
		}
		int l = 0, r = mm + 1;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if (check(m)) {
				r = m;
			}
			else {
				l = m;
			}
		}
		cout << r;
		cout << "\n";
	}
	return 0;
}
