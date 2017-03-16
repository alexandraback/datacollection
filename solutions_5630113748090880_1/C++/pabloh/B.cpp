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

#define FFOR(i,j,n) FOR(i,2*(n)-1) FOR(j,n)

vector<int> solve_case(vector<vector<int>> a, const size_t N)
{
	const int INF = 3000;
	int m = INF;
	FFOR(i, j, N) if (m > a[i][j]) m = a[i][j];
	cout << m << endl;

	size_t c[INF] = {};
	FFOR(i, j, N) ++c[a[i][j]];

	vector<int> r;
	FORi(i, INF) {
		if ((c[i] & 1) == 1)
			r.push_back(i);
	}

	assert(r.size() == N);
	sort(r.begin(), r.end());
	FOR(i, N - 1)
		assert(r[i] < r[i + 1]);

	return r;
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
		int N;
		in >> N; 
		vector<vector<int>> a(2 * N - 1, vector<int>(N));
		FOR(i, 2*N-1) {
			FOR(j, N) {
				in >> a[i][j];
			}
		}

		vector<int> result = solve_case(move(a), N);
		//cout << '\t' << result << endl;
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	//ifstream in("B-small-attempt0.in");
	//ofstream out("B-small-attempt0-out.txt");

	ifstream in("B-large.in");
	ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
