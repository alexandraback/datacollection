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

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		int x, r, c; cin >> x >> r >> c;
		bool richard = false;
		switch(x) {
		case 1:
			break;
		case 2:
			richard = (r*c)%2;
			break;
		case 3:
			richard = (((r*c)%3) != 0) || (r == 1) || (c == 1);
			break;
		case 4:
			richard = (((r*c)%4) != 0) || (r <= 2) || (c <= 2);
			break;
		case 5:
			richard = (((r*c)%5) != 0) || (r <= 2) || (c <= 2);
			break;
		case 6:
			richard = (((r*c)%6) != 0) || (r <= 3) || (c <= 3);
			break;
		default:
			richard = true;
			break;
		}
		if(richard) {
			cout << "Case #" << casenum+1 << ": RICHARD" << endl;
		} else {
			cout << "Case #" << casenum+1 << ": GABRIEL" << endl;
		}
	}

	return 0;
}
