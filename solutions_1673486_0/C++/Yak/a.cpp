// Using C++0x mode in g++ 4.6.0

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
// I used 1.46.1

#include <boost/range/irange.hpp>
#include <boost/range/iterator_range.hpp>

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

double calc(UI A, UI B, vector<double> &p)
{
	double pp = accumulate(p.begin(), p.begin() + A, 1.0, [](double d1, double d2) { return d1 * d2; });
	return pp * (B - A + 1) + (1 - pp) * (B - A + 1 + B + 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI A, B; cin >> A >> B;
		vector<double> p(A);
		for(auto &v : p) { cin >> v; }
		double result = B + 2;
		for(auto i : IR(0U, A+1)) {
			result = min(result, calc(A-i, B, p) + i);
		}
		cout << "Case #" << casenum+1 << ": " << fixed << setprecision(12) << result << endl;
	}

	return 0;
}
