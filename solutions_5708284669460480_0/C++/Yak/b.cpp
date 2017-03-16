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

// acc, max
pair<UI, UI> calc(UI S, UI n, string &t, const string &k, const string &l)
{
	pair<UI, UI> r = { 0, 0 };
	if(n == S) {
		for(auto i: IR(0U, S + 1 - l.size())) {
			if(equal(RNG(l), &t[i])) {
				++r.first; ++r.second;
			}
		}
	} else {
		for(auto i: IR(0U, k.size())) {
			t[n] = k[i];
			auto temp = calc(S, n + 1, t, k, l);
			r.first += temp.first;
			r.second = max(r.second, temp.second);
		}
	}
	return r;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI K, S, L; cin >> K >> L >> S;
		string k, l; cin >> k >> l;
		double result = 0;
		if(S >= L) {
			string t(S, ' ');
			auto r = calc(S, 0, t, k, l);
			result = r.second - r.first / pow(K, S);
		}
		cout << "Case #" << casenum+1 << ": " << setprecision(10) << result << endl;
	}

	return 0;
}
