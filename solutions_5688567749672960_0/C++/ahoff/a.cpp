#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
	int ret = 0;
	while(x) {
		ret *= 10;
		ret += x % 10;
		x /= 10;
		}
	return ret;
}

int main() {
	int cases;
	cin >> cases;
	array<int, 1000001> a;
	for(int count = 1; count <= cases; count++) {
		int n;
		cin >> n;
		fill(a.begin(), a.end(), 0x7fffffff);
		a[0] = 0;
		for(int i = 1; i <= n; i++) {
			a[i] = a[i-1];
			if(reverse(i) < i && i % 10)
				a[i] = min(a[i], a[reverse(i)]);
			a[i]++;
		}
		cout << "Case #" << count << ": " << a[n] << endl;
	}
	return 0;
}

