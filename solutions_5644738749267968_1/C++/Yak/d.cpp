/// gcc version 4.8.2 with -std=c++11

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

int calc_war(const set<double> &naomi, set<double> ken)
{
	int ret = 0;
	for(double i : naomi) {
		auto it = ken.upper_bound(i);
		if(it != ken.end()) {
			ken.erase(it);
		} else {
			ken.erase(ken.begin());
			++ret;
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		set<double> naomi, ken;
		int N; cin >> N;
		for(int i: IR(0, N)) { double t; cin >> t; naomi.insert(t); }
		for(int i: IR(0, N)) { double t; cin >> t; ken.insert(t); }
		size_t result_war = calc_war(naomi, ken);
		size_t result_dwar = naomi.size() - calc_war(ken, naomi);;
		cout << "Case #" << casenum+1 << ": " << result_dwar << ' ' << result_war << endl;
	}

	return 0;
}
