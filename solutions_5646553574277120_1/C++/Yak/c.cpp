// Cygwin clang++ 3.4.2 with -std=c++1y

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
// 1.55 is used

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
		ULL C, D, V; cin >> C >> D >> V;
		vector<ULL> d(D); for(auto &val: d) { cin >> val; }
		ULL ex = 1, can = 0, acc = 0;
		UI result = 0, idx = 0;
		while(can < V) {
//cout << "before:" << ex << ',' << can << ',' << acc << endl;
			while(idx < d.size() && d[idx] < ex) {
				acc += d[idx];
				can = acc * C;
				ex = can + 1;
				++idx;
			}
			if(can >= V) break;
			if(idx < d.size() && d[idx] == ex) {
				++idx;
			} else {
//cout << ex << endl;
				++result;
			}
			acc += ex;
			can = acc * C;
			ex = can + 1;
		}
		cout << "Case #" << casenum+1 << ": " << result << endl;
	}

	return 0;
}
