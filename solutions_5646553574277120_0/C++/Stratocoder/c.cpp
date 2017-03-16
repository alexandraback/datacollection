#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solve_case() {
	int c, d, v;
	cin>>c>>d>>v;
	vector< int > ds(d);
	for (int i = 0; i < d; ++i) {
		cin>>ds[i];
	}
	vector< int > can(v + 1);
	while (accumulate(can.begin(), can.end(), 0) < v) {
		for (int i = 1; i < (1 << ds.size()); ++i) {
			int sm = 0;
			for (int j = 0; j < ds.size(); ++j) {
				sm += ((i >> j) & 1) * ds[j];
			}
			if (sm <= v) {
				can[sm] = 1;
			}
		}
//		for (int i = 0; i < ds.size(); ++i) {
//			cout<<ds[i]<<" ";
//		}
//		cout<<endl;
//		for (int i = 0; i < can.size(); ++i) {
//			cout<<can[i]<<" ";
//		}
//		cout<<endl;
		if (accumulate(can.begin(), can.end(), 0) < v) {
			int mn = 1;
			while (mn <= ds.size() && ds[mn - 1] == mn) {
				++mn;
			}
			ds.push_back(mn);
			sort(ds.begin(), ds.end());
		}
	}
	return ds.size() - d;
}

int main() {
	int tt;
	cin>>tt;
	for (int t = 1; t <= tt; ++t) {
		cout<<"Case #"<<t<<": "<<solve_case()<<endl;
	}
	return 0;
}

