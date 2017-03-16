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
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)


long long solve_case(const int E, const int R, const vector<int> & v)
{
	const int N = v.size();

	//DP backwards
	vector<long long> g1(E+1); //gain(j)
	vector<long long> g2(E+1); //gain(j+1)
	FORi(e,E+1) g2[e] = v[N-1]*e;
	for (int i = N-2; i >= 0; --i) {
		FORi(e,E+1) {
			long long mx = 0;
			FORi(s,e+1) {
				int remain = min(e - s + R, E);
				long long gg = static_cast<long long>(s)*v[i] + g2[remain];
				mx = max(mx, gg);
			}
			g1[e] = mx;
		}
		swap(g1,g2);
	}
	return g2[E];
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int E, R, N;
		in >> E >> R >> N;
		vector<int> v(N);
		FOR(i,N) in >> v[i];

		long long result = solve_case(E, R, v);
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
