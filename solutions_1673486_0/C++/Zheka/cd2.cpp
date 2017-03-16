#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{	
	
	int n; 
	cin >> n;
	for (int tc = 0; tc < n; ++tc) {
		int a, b; 
		cin >> a>> b;
		vector<double> p(a, 0);
		cin >> p[0];
		for (int i = 1; i < a; ++i) {
			cin >> p[i];
			p[i] *= p[i-1];
		}

		vector<double> pres;
		int toType = b - a;
		double min = (1 + toType) * p.back() + (toType + b + 2)*(1 - p.back());
		double tmp1 = (1 + 1 + b);
		if (tmp1 < min) min = tmp1;

		for (int i = 1; i <= a; ++i) {
			double x = (i != a ? p[a -1 - i] : 1);
			double tmp = (2 * i + 1 + toType) *x  + (2 * i + 1 + toType + b  + 1)*(1 - x);
			if (tmp < min) min = tmp;
		}
		cout.precision(6);
		cout << "Case #" << tc +1 << ": ";
		printf("%.6f", min);
		if (tc < n -1) cout << endl;
	}
}