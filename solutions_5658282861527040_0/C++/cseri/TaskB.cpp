#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>

//#include <boost/multiprecision/cpp_int.hpp> 
typedef long long ll;

using namespace std;



struct Task
{
	ll solve(const int a, const int b, const int k)
	{
		int ok = 0;

		for (int ca = 0; ca < a; ++ca) {
			for (int cb = 0; cb < b; ++cb) {
				int winner = ca & cb;
				if (winner < k) ++ok;
			}
		}

		return ok;
	}
};



int main() {
	string fnsuffix = "_s.txt";
	ifstream f("input" + fnsuffix);
	ofstream o("output" + fnsuffix);
	istream &in = f;

	int tn = -1;
	in >> tn;
	if (tn < 0)
	{
		cerr << "Error reading input." << endl;
	}

	for (int ti = 0; ti < tn; ++ti)
	{
		int a, b, k;
		in >> a >> b >> k;

		Task t;
		auto sol = t.solve(a, b, k);

		ll res = sol;

		o << "Case #" << (ti + 1) << ": " << res << endl;
		cerr << "Case #" << (ti + 1) << ": " << res << endl;
	}

	system("pause");

	return 0;
}


