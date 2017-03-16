#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define LL long long

LL solve(LL x) {
	if (x % 10 == 0)
		return solve(x - 1) + 1;
	if (x < 10)
		return x;
	int res = 0;
	vector<int> v;
	while (x > 0) {
		v.push_back(x % 10);	
		x = x / 10;
	}
	int n = v.size();
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) {
			res += v[i] - 1;
		} else {
			res += v[i] * pow(10, min(i, n - 1 - i));
		}
	}
	for (int i = (n + 1) / 2; i < n; i++) {
		if (i < n - 1 && v[i] > 0) {
			res++;
			break;
		} else if (v[i] > 1) {
			res++;
			break;
		}
	}
	LL nex = pow(10, n - 1) - 1;
	res += solve(nex) + 2;
	return res;
}

int main() {
	int nt;
	cin >> nt;
	LL x;
	for (int i = 0; i < nt; i++) {
		cin >> x;
		cout << "Case #" << i + 1 << ": ";
		cout << solve(x) << endl;
	}
	return 0;
}
