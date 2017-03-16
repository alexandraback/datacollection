#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }



double solve_case(const double C, const double F, const double X)
{
	const double r = 2;
	//cout << C << '\t' << F << '\t' << X << '\t' << '\t' << (X/C-r/F) << '\n';
	double s = C/r; double tmin = X/r; 
	//cout << tmin << ' ';
	int k = 1;
	for (; ; ++k) {
		double t = X/(r + k*F) + s;
		s += C/(r + k*F);
		//cout << t << ' ';
		if (t >= tmin) break;
		tmin = t;
	}
	//cout << tmin << '\t' << k;
	//cout << endl;

	return tmin;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		double C, F, X;
		in >> C >> F >> X;

		double result = solve_case(C, F, X);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-out.txt");

	//ifstream in("B-large.in");
	//ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
