// gcc version 4.8.1 20130328 (prerelease) (GCC) at http://www.drangon.org/mingw/
// with -std=c++11

#include <iostream>
#include <sstream>
#include <iomanip>

#include <iterator>

#include <algorithm>
#include <numeric>
#include <utility>
#include <limits>

#include <string>

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#include <tuple>
#include <initializer_list>

#include <cmath>

// Boost library can be retrieved from http://www.boost.org/
// 1.52 is used

#pragma GCC diagnostic ignored "-Wconversion"
#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>
#pragma GCC diagnostic warning "-Wconversion"

typedef unsigned long long ULL;
typedef long long LL;
typedef unsigned long UL;
typedef unsigned int UI;
typedef unsigned short US;
typedef unsigned char UC;

#define RNG(v) (v).begin(), (v).end()
#define REP(v, e) for(UI v = 0U; v < e; ++v)
#define REP_(v, s, e) for(UI v = s; v < e; ++v)
#define REPV(v, e) for(v = 0; v < e; ++v)
#define REPV_(v, s, e) for(v = s; v < e; ++v)

using namespace std;

template<class Integer>
inline boost::iterator_range< boost::range_detail::integer_iterator<Integer> >
IR(Integer first, Integer  last)
{ return boost::irange(first, last); }

inline ULL mygcd(ULL m, ULL n)
{
	if(m < n) std::swap(m, n);
	while(n != 0) {
		long long r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		ULL P, Q; char c;
		cin >> P >> c >> Q;
		ULL d = mygcd(P, Q);
		P /= d; Q /= d;
		ULL i = 1;
		bool f = false;
		while(Q >= i) {
			if(Q == i) {
				f = true; break;
			}
			i <<= 1;
		}
		if(f) {
			ULL j = 1, jj = 0;
			while(P * j < Q) { ++jj; j <<= 1; }
			cout << "Case #" << casenum+1 << ": " << jj << endl;
		} else {
			cout << "Case #" << casenum+1 << ": impossible" << endl;
		}
	}

	return 0;
}
