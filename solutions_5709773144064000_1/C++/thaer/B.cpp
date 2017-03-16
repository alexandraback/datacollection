//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

const double eps = 0.00000001;

int main() {
	freopen("output.txt", "w", stdout);
	double C, F, X;
	int t, tc = 0;
	cin>>t;
	while (tc++ < t) {
		double nf, pos, acc, f, tot;
		cin>>C>>F>>X;
		acc = pos = nf = 0.0;
		f = 2.0;
		tot = X / f;
		while (true) {
			pos = acc + C/f;
			nf = f + F;
//			cout<<"tot "<<tot<<endl;
//			cout<<"pos "<<pos<<endl;
//			cout<<"f "<<f<<endl;
			if (pos + X/nf < tot + eps) {
				tot = pos + X/nf;
				f = nf;
				acc = pos;
			} else {
				break;
			}
		}
		printf("Case #%d: %.7lf\n", tc, tot);
	}
	return 0;
}