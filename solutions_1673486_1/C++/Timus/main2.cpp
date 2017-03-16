#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);

	int tests;
	cin >> tests;
	for (int testnum = 1; testnum <= tests; ++testnum) {
//		cerr << "_______________________" << endl;
		int A, B;
		cin >> A >> B;
		vector<double> p;
		p.resize(A);
		double pr = 1;
		for(int i = 0; i < A; ++i)
			cin >> p[i], pr *= p[i];
		vector<double> ans;
		ans.resize(A + 10);
		ans[0] = pr * (B - A + 1) + (1 - pr) * (B - A + 1 + B + 1);
		ans[1] = 1 + B + 1;
		pr = 1;
		for (int i = 0; i < A; ++i) {
			ans[2 + i] = pr * (A - i + (B - i) + 1) + (1 - pr) * (A - i + (B - i) + 1 + B + 1);
//			cerr << ans[2 + i] << endl; 
			pr *= p[i];
		}
		double best = 1e9;
		for (int i = 0; i < 2 + A; ++i)
			best = min(best, ans[i]);
		printf("Case #%d: %.7f\n", testnum, best);
	}
	return 0;
}
