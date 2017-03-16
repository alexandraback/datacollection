#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
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

//template<class C>
//void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

inline vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
long long solve_case(const string & s, int n)
{
	const size_t sz = s.size();
	const long long szl = sz;
	assert(sz > 0);
	long long nval = 0;
	size_t b0 = -1; //prev cons str start
	size_t cons = 0;
	FOR(i,sz) {
		if (vowel(s[i])) 
			cons = 0;
		else {
			++cons;
			if (cons >= n) {
				size_t b1 = i - n + 1;
				size_t e = i;
				nval += (b1 - b0)*(szl - e);
				b0 = b1;
			}
		}
	}
	return nval;
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
		int n;
		in >> s >> n;

		long long result = solve_case(s, n);
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
