#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Password Problem

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int A, B;
		cin >> A >> B;
		vector <double> p(A);
		for (int i = 0; i < p.size(); i++) {
			cin >> p[i];
		}
		double ret = ((A == 0) ? 1 : 2) + B;
		double prob = 1;
		for (int i = 0; i <= A; i++) {
			ret = min(ret, (A - i) + (B - i) + 1 + (1 - prob) * (B + 1));
			prob *= p[i];
		}
		printf("Case #%d: %.9f\n", caseno, ret);
	}

	return 0;
}
