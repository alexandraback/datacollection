
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>


using namespace std;

int main() {
	cout.precision(20);
	cerr.precision(20);

	int tn;
	cin >> tn;

	for (int ti = 0; ti < tn; ti++) {

		double a, b;
		cin >> a >> b;

		vector<double> v;
		v.resize(a);
		cerr << a << " " << b << endl;

		for (int i = 0; i < a; ++i)
		{
			cin >> v[i];
		}


		//case 3
		double minexp = b + 2;

		//case 1-2
		double exp_helper = 1.0; //typed correctly before
		for (double backspaces = a; backspaces >= 0; --backspaces)
		{
			double correctrem = (b - a) + backspaces + 1;
			double incorrectrem = correctrem + b + 1;

			double exp = backspaces +
				(correctrem) * (exp_helper) + //correct
				(incorrectrem) * (1 - exp_helper); //incorrect

			//cerr << "BS: " << backspaces << ", exp_helper: " << exp_helper << ", exp: " << exp << endl;

			if (exp < minexp) minexp = exp;

			//prepare for next round
			exp_helper *= v[a-backspaces];
		}

		cout << "Case #" << ti+1 << ": " << minexp << endl;
		cerr << "Case #" << ti+1 << ": " << minexp << endl;
	}
}

