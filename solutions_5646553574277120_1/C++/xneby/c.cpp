#include <bits/stdc++.h>
using namespace std;

int test() {
	int c, d, v;
	cin >> c >> d >> v;
	vector<long long> D;
	for(int i=1; i<=d; i++) {
		int x;
		cin >> x;
		D.push_back(x);
	}

	sort(D.begin(), D.end());

	long long nie = 1;
	int wy = 0;
	int idx = 0;

	while(nie <= v) {
		while(idx < d && nie >= D[idx]) {
			nie += D[idx] * c;
			idx ++;
		}
		if(nie <= v) {
			wy ++;
			nie += nie * c;
		}
	}

	return wy;
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": " << test() << endl;
	}
}
