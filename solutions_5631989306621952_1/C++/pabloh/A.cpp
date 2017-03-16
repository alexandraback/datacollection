#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;
//typedef Int<100> num;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }



string solve_case(string s)
{
	if (s.empty()) return s;
	auto m = max_element(s.begin(), s.end());
	string z = solve_case(move(s.substr(0,m-s.begin())));
	string p;
	char c = *m;
	for (; m != s.end(); ++m) {
		if (*m == c)
			p += *m;
		else
			z += *m;
	}
	//sort(z.begin(), z.end(), less<>());
	//cout << s << '\t' << z << '\n';
	return p + z;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		string s;
		in >> s;

		string result = solve_case(move(s));
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	//ifstream in("A-small-attempt0.in");
	//ofstream out("A-small-attempt0-out.txt");

	ifstream in("A-large.in");
	ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
