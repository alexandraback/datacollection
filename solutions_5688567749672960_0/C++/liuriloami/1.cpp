#include <bits/stdc++.h>
using namespace std;

long long int inv (long long int n ) {
	long long int res = 0;
	if (n%10 == 0) return INT_MAX;
	while (n != 0) {
		res = res*10 + n%10;
		n /= 10;
	}
	return res;
}

void solve() {
	long long int n, cur = 1;
	cin >> n;
	long long int res[n+1];
	for (int i = 1; i <= n; i++)
		res[i] = n+1;
	res[1] = 1; 
	for (int i = 2; i <= n; i++) {
		if (inv(i) > i)
			res[i] = 1+res[i-1];
		else 
			res[i] = min(1+res[i-1], 1+res[inv(i)]);
	}
	cout << res[n] << endl;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}