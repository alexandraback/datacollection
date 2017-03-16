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

template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

size_t solve_case(int A, const vector<long long> & m)
{
	const size_t N = m.size();
	if (A == 1) return N;

	long long s = A;
	size_t j = 0;
	size_t added = 0;
	size_t best = N; //borrar todos

	while (j < N) {
		while (j < N && s > m[j]) {
			s += m[j];
			++j;
		}
//		if (j == N) return added;
		if (added + N-j < best) best = added + N-j;
		if (j == N) return best;

		assert(j < N && s <= m[j]);
		size_t k = 0;
		while (s <= m[j]) {
			s += s-1;
			++k;
		}
		//if (k > N-j) return added + N-j;
		//else 
			added += k;
	}
	assert(j == N);
//	return added;
	return best;
}

void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int A, N;
		in >> A >> N;
		vector<long long> m(N);
		FOR(i,N) in >> m[i];
		sort(m.begin(), m.end());


		size_t result = solve_case(A, m);
//		assert(result <= N);
		if (result > N) {
			vector<long long> a(N);
			partial_sum(m.begin(), m.end(), a.begin());

			cout << A << endl;
			show(m);
			show(a);
			cout << result << endl;

			result = N;
		}
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	//ifstream in("A-small-attempt0.in");
	//ofstream out("A-small-out.txt");

	ifstream in("A-large.in");
	ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
