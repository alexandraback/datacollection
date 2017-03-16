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


ll GCD(ll u, ll v) {
	while (v != 0) {
		ll r = u % v;
		u = v;
		v = r;
	}
	return u;
}

struct Task
{
	ll solve(ll p, ll q)
	{
		//simplify
		ll x = GCD(p, q);
		p /= x;
		q /= x;

		cout << p << "/" << q << endl;

		bool ok = false;
		int n = 0;
		for (int i = 0; i < 50; ++i)
		{
			if (q == 1ll << i) {
				ok = true;
				n = i;
				break;
			}
		}
		if (!ok) return -1;

		for (int i = 0; i < 50; ++i)
		{
			if (p >> (n - i)) {
				return i;
			}
		}

		return -1;
	}
};



int main() {
	string fnprefix = "A-large";
	//string fnprefix = "A-small-attempt0";
	//string fnprefix = "A-example";
	ifstream f(fnprefix + ".in");
	ofstream o(fnprefix + ".out");
	istream &in = f;

	int tn = -1;
	in >> tn;
	if (tn < 0)
	{
		cerr << "Error reading input." << endl;
	}

	for (int ti = 0; ti < tn; ++ti)
	{
		ll p;
		char ch;
		ll q;
		in >> p >> ch >> q;

		Task t;
		auto sol = t.solve(p, q);

		string res = -1 == sol ? string("impossible") : to_string(sol);

		o << "Case #" << (ti + 1) << ": " << res << endl;
		cerr << "Case #" << (ti + 1) << ": " << res << endl;
	}

	system("pause");

	return 0;
}


