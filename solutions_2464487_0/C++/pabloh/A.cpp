#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
//download TTMath from http://www.ttmath.org/
#include <ttmath/ttmath.h>

using namespace std;
using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)

//typedef long long Num;
typedef Int<8> Num;

inline Num f(Num y, Num r)
{
	return y*((r+y)*2-1); //y*(2r+1) + 2(y-1)y
}

Num solve_case(Num r, Num t)
{
	Num y = 1, b = t; //b = t/2; b.Sqrt(); b += 1;
	if (f(y,r) > t) return -1;
	if (f(b,r) <= t) return -1;
	while(y+1 < b) {
		Num m = y + (b-y)/2;
		if (f(m,r) <= t) y = m;
		else b = m;
	}
	return y;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		Num r, tt;
		in >> r >> tt;

		Num result = solve_case(r,tt);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-out.txt");

	//ifstream in("A-large.in");
	//ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
