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

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }
ostream& operator<<(ostream& os, const vector<int> & v)
{
	FOR(i, v.size()) os << ' ' << v[i] ;
	return os;
}

pair<int, int> s(int c, int j, size_t i, const string & C, const string & J)
{
	if (i == C.size())
		return pair<int, int>(c, j);

	if (C[i] == '?') {
		if (J[i] == '?') {
			int x = 0;
			int y = 0;
			auto r = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			x = 0;
			y = 1;
			auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 0;
			y = 9;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 1;
			y = 0;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 1;
			y = 1;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 1;
			y = 9;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 9;
			y = 0;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 9;
			y = 1;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 9;
			y = 9;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			return r;
		} else {
			int y = J[i] - '0';
			int x = y;
			auto r = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (y > 0)
			{
				x = y-1;
				auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) <= abs(r.first - r.second))
					r = r1;
			}
			if (y < 9)
			{
				x = y + 1;
				auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) < abs(r.first - r.second))
					r = r1;
			}
			x = 0;
			auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			x = 9;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			return r;
		}
	} else {
		int x = C[i] - '0';
		if (J[i] == '?') {
			int y = x;
			auto r = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (x > 0)
			{
				y = x-1;
				auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) <= abs(r.first - r.second))
					r = r1;
			}
			if (x < 9)
			{
				y = x + 1;
				auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) < abs(r.first - r.second))
					r = r1;
			}
			y = 0;
			auto r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			y = 9;
			r1 = s(c * 10 + x, j * 10 + y, i + 1, C, J);
			if (abs(r1.first - r1.second) < abs(r.first - r.second))
				r = r1;
			return r;
		}
		else {
			int y = J[i] - '0';
			return s(c * 10 + x, j * 10 + y, i + 1, C, J);
		}
	}
}

pair<int, int> ss(int c, int j, size_t i, const string & C, const string & J)
{
	if (i == C.size())
		return pair<int, int>(c, j);

	int dif = numeric_limits<int>::max();
	pair<int, int> r;
	if (C[i] == '?') {
		if (J[i] == '?') {
			for (int x = 0; x < 10; ++x)
				for (int y = 0; y < 10; ++y) {
					auto r1 = ss(c * 10 + x, j * 10 + y, i + 1, C, J);
					if (abs(r1.first - r1.second) < dif)
					{
						r = r1;
						dif = abs(r1.first - r1.second);
					}
				}
			return r;
		}
		else {
			int y = J[i] - '0';
			for (int x = 0; x < 10; ++x) {
				auto r1 = ss(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) < dif)
				{
					r = r1;
					dif = abs(r1.first - r1.second);
				}
			}
			return r;
		}
	}
	else {
		int x = C[i] - '0';
		if (J[i] == '?') {
			for (int y = 0; y < 10; ++y) {
				auto r1 = ss(c * 10 + x, j * 10 + y, i + 1, C, J);
				if (abs(r1.first - r1.second) < dif)
				{
					r = r1;
					dif = abs(r1.first - r1.second);
				}
			}
			return r;
		}
		else {
			int y = J[i] - '0';
			return ss(c * 10 + x, j * 10 + y, i + 1, C, J);
		}
	}
}

string solve_case(string C, string J)
{
	assert(C.size() == J.size());
	auto r = s(0, 0, 0, C, J);
	string cc = to_string(r.first);
	string jj = to_string(r.second);
	return string(C.size() - cc.size(), '0') + cc + ' ' + string(J.size() - jj.size(), '0') + jj;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		//cout << "Case #" << t << endl;
		string C, J;
		in >> C >> J;

		string result = solve_case(move(C), move(J));
		//cout << '\t' << result << endl;
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt1.in");
	ofstream out("B-small-attempt1-out.txt");

	//ifstream in("B-large.in");
	//ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
