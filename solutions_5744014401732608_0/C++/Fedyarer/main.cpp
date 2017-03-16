#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 1000;

const int N = 4;

void print (vector <int> &ans, int b) {
	cout << "POSSIBLE" << endl;
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < b; j++) {
			if (j < b - 1) {
				if (j > i)
					cout << 1;
				else
					cout << 0;
			} else
				cout << ans[i] << endl;
		}
	}
}


int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int t;
	
	cin >> t;
	for (int it = 1; it <= t; it++) {
		cout << "Case #" << it << ": ";
		int b;
		long long m;
		cin >> b >> m;
		vector <long long> tp;
		tp.push_back(1);
		tp.push_back(1);
		for (int i = 1; i < b; i++) {
			tp.push_back(tp[i] * 2);
		}
//		for (int i = 0; i < tp.size(); i++) {
//			cerr << tp[i] << endl;
//		}
//		cerr << "m = " << m << endl;
//		cerr << "b = " << b << endl;
//		cerr << "tp.size() = " << tp.size() << endl;
//		cerr << "tp[b] = " << tp[b] << endl;
		if (tp[b- 1] < m) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		vector <int> ans;
		ans.resize(b, 0);
		long long old_m = m;
		for (int i = b - 2; i >= 0; i--) {
//			cerr << "m = " << m << endl;
//			cerr << "i = " << i << endl;
//			cerr << "tp[i] = " << tp[i] << endl;
			if (m >= tp[i]) {
				ans[i] = 1;
				m -= tp[i];
			}
//			cerr << m << endl;
		}
		assert(m == 0);
		print(ans, b);
	}
	
	
	return 0;
}