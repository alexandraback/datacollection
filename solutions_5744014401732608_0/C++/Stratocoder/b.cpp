#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin>>t;
	for (int tt = 1; tt <= t; ++tt) {
		long long b, m;
		cin>>b>>m;
		long long mx = 1L << (b - 2);
		if (m > mx) {
			cout<<"Case #"<<tt<<": IMPOSSIBLE"<<endl;
			continue;
		} else {
			cout<<"Case #"<<tt<<": POSSIBLE"<<endl;
		}
		vector< vector< int > > v(b);
		for (int i = 0; i < b; ++i) {
			v[i].resize(b);
			fill(v[i].begin(), v[i].end(), 0);
			if ((i > 0) && (i < (b - 1))) {
				fill(v[i].begin() + i + 1, v[i].end(), 1);
			}
		}
		for (int i = b - 2; i > 0; --i) {
			long long amount = 1L << (i - 1);
			if (m >= amount) {
				v[0][b - i - 1] = 1;
				m -= amount;
			}
		}
		if (m) {
			v[0][b - 1] = 1;
		}
		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				cout<<v[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
