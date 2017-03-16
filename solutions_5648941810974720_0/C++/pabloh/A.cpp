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

const char * nm[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
const size_t NL = 'Z' - 'A' + 1;
string solve_case(string s)
{
	size_t c[NL] = {};
	FOR(i, s.size()) ++c[s[i]-'A'];
	const int w[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	const char r[10] = { 'Z', 'W', 'U', 'X', 'G', 'O', 'R', 'F', 'S', 'I' };
	size_t ph[10] = {};
	FOR(i, 10) {
		char rr = r[i];
		int k = w[i];
		while (c[rr - 'A']) {
			++ph[k];
			const char * p = nm[k];
			while (*p) {
				--c[(*p) - 'A'];
				++p;
			}
		}
	}
	string res;
	FOR(i, 10) {
		if (ph[i]) {
			char d = i + '0';
			res += string(ph[i], d);
		}
	}
	return res;
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
	FOR(i, NL) {
		cout << static_cast<char>(i + 'A');
		FORi(k, 10) {
			const char * p = nm[k];
			while (*p) {
				if (*p == i + 'A')
					cout << k;
				++p;
			}

		}
		cout << endl;
	}
	//return 0;

	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-attempt0-out.txt");

	//ifstream in("A-large.in");
	//ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
