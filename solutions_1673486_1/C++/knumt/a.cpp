#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <map>
#include <string>

using namespace std;


void dump_e(vector<double> e) {
	cout << ">>" << endl;
	for (int i=0; i<e.size(); i++) {
		cout << e[i] << endl;

	}
	cout << "<<" << endl;
}

double each_case(int A, int B, vector<double> &v) {
	int s = 2 << A;

	/*
	// debug
	cout << A << B << endl;
	dump_e(v);
	*/

	double keep_p = 1.0;
	for (int i=0; i<A; i++) {
		keep_p *= v[i];
	}

	double cand = (double)(B+2);
	double keep = keep_p * (B-A+1) + (1 - keep_p) * (B * 2 - A + 2);
	if (cand > keep) cand = keep;

	vector<double> expected;
	for (int k=1; k<A; k++) {
		double tt = keep_p * (B-A+1+ k*2);
		expected.push_back(tt);
	}
//	dump_e(expected);

	keep_p =  1.0;
	for (int i=0; i<A; i++) {
		double fail_p = keep_p * (1 - v[i]);
		for (int k=1; k<A; k++) {

			if (k+i+1 >A) {
				// first miss in i && recoverable
				expected[k-1] += fail_p * (B - A + 1 + k * 2);
			} else {
				// first miss in i && unrecoverable
				expected[k-1] += fail_p * (B * 2 - A + 2 + k * 2);
			}
		}	
		keep_p *= v[i];
		//dump_e(expected);
	}

	for (int i=0; i<A-1; i++) {
		if (cand > expected[i]) {
			cand = expected[i];
//			cerr << "min : " << i << endl;
		}
	}
	return cand;	
}

int main(void) {
	int t;
	cin >> t;

	for (int i=0; i<t; i++) {
		int a, b;
		cin >> a >> b;
		vector<double> v;
		for (int j=0; j<a; j++) {
			double tt;
			cin >> tt;
			v.push_back(tt);
		}
		cout << "Case #" << (i+1) << ": ";
		double ret = each_case(a, b, v);
		cout << setprecision(6) << setiosflags(ios::fixed);
		cout << ret << endl;
	}

}
