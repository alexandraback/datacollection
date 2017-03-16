#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
// #include <queue>
#include <cmath>
#include <cstdint>
//download TTMath from http://www.ttmath.org/
// #include "ttmath-0.9.3/ttmath/ttmath.h"
#undef max
#undef min

using namespace std;
// using namespace ttmath;
// typedef Int<100> num;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
// template<class C> void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }
// ostream& operator<<(ostream& os, const vector<int> & v) { FOR(i, v.size()) os << ' ' << v[i]; return os; }


string solve_case(int B, int64_t M)
{
	assert(B < 63);
	int64_t k = 1;
	k <<= B-2;
	if (M > k) return "IMPOSSIBLE";
	string res("POSSIBLE");
	if (M == k) { 
		res += '\n'; res += '0'; res += string(B-1,'1'); 
	} else {
		assert(M < k);
		res += '\n'; 
		res += '0'; 
		string s;
		FORi(i,B-2) { s += (M & 1 ? '1' : '0'); M >>= 1; }
		reverse(s.begin(), s.end());
		res += s;
		res += '0';
	}
	FOR(i,B-1) {
		res += '\n';
		res += string(i+2,'0');
		res += string(B-2-i,'1');
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
		// cout << "Case #" << t << endl;
		int B; int64_t M;
		in >> B >> M;

		string result = solve_case(B, M);
		//cout << '\t' << result << endl;
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	// ifstream in("B-sample.in");
	// ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0-out.txt");

	// ifstream in("B-large.in");
	// ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
