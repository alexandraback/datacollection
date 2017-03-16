#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int MN = 200 + 10;

int arr[MN], n;

bool f(double mid, int pos, double sum) {
	double all = 1.0 - mid;
	double k = mid * sum + arr[pos];
	for(int i = 0; i < n; i ++) {
		if (i == pos)
			continue;
		double need = (k - arr[i]) / sum;
		all -= max(need, 0.0);
	}
	return (all < 0);
}


double solve(int pos, double sum) {
	double lf = 0.0, rg = 1, ans = 1;
	for(int iter = 0; iter < 100; iter ++) {
		double mid = (lf + rg) * 0.5;
		if (f(mid, pos, sum)) {
			rg = mid;
			ans = min(ans, mid);
		}
		else lf = mid;
	}
	return ans;
}

int main () {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for(int k = 0; k < t; k ++) {
		cin >> n;
		double sum = 0;
		for(int i = 0; i < n; i ++) {
			cin >> arr[i];
			sum += arr[i];
		}
		printf("Case #%d: ", k + 1);
		for(int i = 0; i < n; i ++) {
			double ans = solve(i, sum);
			printf("%.10lf ", ans * 100);
		}
		cout << endl;
	}
	return 0;
}