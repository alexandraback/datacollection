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

const int N = 1000000;
vector<int> c(N+1), prev(N+1);


int solve_case(int n)
{
	assert(n <= N);
	int res = c[n];
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
		int n;
		in >> n;

		int result = solve_case(n);
		out << "Case #" << t << ": " << result << endl;
	}
}

int rev(int n)
{
	int m = 0;
	while (n) {
		m = m*10 + n%10; n /= 10;
	}
	return m;
}
void test_rev()
{
	FORi(i,1000) cout << i << '/' << rev(i) << ' ';
	cout << endl;
}
void precomp(vector<int> & c, vector<int> & prev)
{
	const int N = c.size()-1;
	int n = 0;
	c[n] = 0;
	prev[n] = 0;
	++n;
	c[n] = 1;
	prev[n] = 1;
	++n;
	for (;n < 10; ++n) {
		c[n] = c[n-1]+1;
		prev[n] = n-1;
	}
	for (;n <= N; ++n) {
		int m = rev(n);
		if (m >= n || n%10 == 0) {
			c[n] = c[n-1]+1;
			prev[n] = n-1;
		} else {
			assert(m < n && m > 0);
			if (c[m]+1 < c[n-1]+1) {
				c[n] = c[m]+1;
				prev[n] = m;
			} else {
				c[n] = c[n-1]+1;
				prev[n] = n-1;
			}
		}
	}
}

int main()
{
	//test_rev();
	//return 0;

	precomp(c,::prev);
	//show(c);
	//FOR(i,N) 
	//	if (prev[i] != i-1)
	//		cout << i << '\t' << c[i] << '\t' << prev[i] << '\n';
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
