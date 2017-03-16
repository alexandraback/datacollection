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

const int N = 10000000;
vector<int> c(N+1), prev(N+1);

long long rev(long long n)
{
	long long m = 0;
	while (n) {
		m = m*10 + n%10; n /= 10;
	}
	return m;
}
int cif(long long n)
{
	int m = 0;
	while (n) {
		n /= 10; ++m;
	}
	return m;
}

void test_rev()
{
	FORi(i,1000) cout << i << '/' << rev(i) << ' ';
	cout << endl;
}
void test_cif()
{
	FORi(i,10007) cout << i << '/' << cif(i) << ' ';
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

int solve_case_easy(int n)
{
	assert(n <= N);
	int res = c[n];
	return res;
}

const int p[] = {
	1, 
	10, 
	100, 
	1000,
	10000, 
	100000, 
	1000000,
	10000000, 
	100000000, 
	1000000000,
};
long long solve_case(long long n)
{
	long long res = 0;

	while (n > 10) {
		int d = (cif(n)+1)/2;
		assert(d < 10);
		int m = n % p[d];
		if (m == 0) {
			--n; ++res;
		} else if (m == 1) {
			long long r = rev(n);
			if (r < n) {
				n = r;
				++res;
			} else {
				--n; ++res;
			}
		} else {
			assert(m > 1);
			--m;
			n -= m;
			res += m;
			assert(n % p[d] == 1);
		}
	}
	assert(n <= 10);
	res += n;
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
		long long n;
		in >> n;

		long long result = solve_case(n);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//test_rev();
	//test_cif();
	//return 0;

	//using ::prev;
	//precomp(c,prev);
	//////show(c);
	////FOR(i,N) 
	////	if (prev[i] != i-1)
	////		cout << i << '\t' << c[i] << '\t' << prev[i] << '\n';
	//FOR(i,N) {
	//	long long r = solve_case(i);
	//	if (c[i] != r)
	//		cout << i << '\t' << c[i] << '\t' << prev[i] << '\t' << r <<'\n';
	//}
	//return 0;

	//ifstream in("A-sample.in");
	//ofstream out("A-sample-out.txt");

	//ifstream in("A-small-attempt0.in");
	//ofstream out("A-small-attempt0-out.txt");

	ifstream in("A-large.in");
	ofstream out("A-large-out.txt");

	solve(in,out);

	return 0;
}
