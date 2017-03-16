#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int t;
long long n;
const int INF = 1000000000;

int ans[1000010];

int reverse(int x) {
	int a = 0;
	while (x != 0) {
		a *= 10;
		a += x % 10;
		x /= 10;
	}
	return a;
}

int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			ans[j] = INF;
		}
		ans[1] = 1;

		for (int j = 1; j <= n; j++) {
			int k = reverse(j);
			ans[j + 1] = min(ans[j] + 1, ans[j + 1]);	
			ans[k] = min(ans[j] + 1, ans[k]);	
		}
		cout << "Case #" << i + 1 << ": " << ans[n] << endl;
	}
	return 0;
}
