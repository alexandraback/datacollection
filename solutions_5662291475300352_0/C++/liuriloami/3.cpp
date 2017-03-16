#include <bits/stdc++.h>
using namespace std;

int n;
vector<double> posP, velP;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double d, h, m;
		cin >> d >> h >> m;
		for (int j = 0; j < h; j++) {
			posP.push_back(d-1);
			velP.push_back(360.0f/(m+j));
		}
	}
	int res = 2;
	int t0 = (360.0f-posP[0])/velP[0];
	int t1 = (360.0f-posP[1])/velP[1];
	if (t0 > t1) {
		int p = posP[1] + velP[1]*t0;
		if (p > 720) res = 1;
		else res = 0;
	} else if (posP[0] != posP[1] || velP[0] != velP[1]){
		int p = posP[0] + velP[0]*t1;
		if (p > 720) res = 1;
		else res = 0;
	}
	cout << res << endl;
	
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		velP.clear(); posP.clear();
		cout << "Case #" << i+1 << ": ";
		solve();
	}
	return 0;
}