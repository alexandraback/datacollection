#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<double> &a, vector<double> &b){
	int n = a.size();
	int idx = 0;
	for (int i = 0; i < n; ++i){
		if (b[idx] < a[i]) ++idx;
	}
	return idx;
}

int main(){
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; ++Case){
		int n;
		cin >> n;
		vector<double> a(n), b(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		printf("Case #%d: %d %d\n", Case, check(a, b), n-check(b, a));
	}

	return 0;
}