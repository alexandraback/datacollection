#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int solve_war(vector<double> a, vector<double> b) {
	int res = 0;
	int n = (int)a.size();
	for(int i=n-1;i>=0;i--) {
		int j = 0;
		while (j<b.size() && b[j]<a[i]) {
			++j;
		}
		if (j==b.size()) {
			++res;
			b.erase(b.begin(), b.begin()+1);
		} else {
			b.erase(b.begin()+j, b.begin()+j+1);
		}
	}
	return res;
}

int solve_war_nya(vector<double> a, vector<double> b) {
	int n = (int) a.size();
	int i = n-1;
	int j = n-1;
	int res = 0;
	while (i>=0) {
		if (a[j] > b[i]) {
			res++;
			--j;
		}
		--i;
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tcs;
	cin >> tcs;
	int tc=0;
	while (tcs--) {
		tc++;
		int n;
		cin >> n;
		vector<double> a(n);
		vector<double> b(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		for(int i=0;i<n;i++) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		printf("Case #%d: %d %d\n", tc, solve_war_nya(a, b), solve_war(a, b));
	}



	return 0;
}