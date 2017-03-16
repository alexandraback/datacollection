// Cygwin clang++ 3.7.1 with -std=c++1z

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
// 1.58 is used

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
		UI n; cin >> n;
		map<string, UI> conv;
		vector<UI> w1(n), w2(n);
		UI idx = 0;
		REP(i, n) {
			string s; cin >> s;
			if(!conv.count(s))
				conv[s] = idx++;
			w1[i] = conv[s];
			cin >> s;
			if(!conv.count(s))
				conv[s] = idx++;
			w2[i] = conv[s];
		}
		UI result = 0;
		REP(i, 1U<<n) {
			set<UI> c1, c2; UI tmp=0;
			for(UI ii = i, idx = 0; idx < n; ii>>=1, ++idx) {
				if(ii&1) {
					c1.insert(w1[idx]);
					c2.insert(w2[idx]);
				} else ++tmp;
			}
			bool check = true;
			for(UI ii = i, idx = 0; idx < n; ii>>=1, ++idx) {
				if((ii&1) == 0) {
					if(c1.count(w1[idx]) == 0 || c2.count(w2[idx]) == 0) {
						check = false;
						break;
					}
				}
			}
			if(check && tmp > result) result = tmp;
		}
		cout << "Case #" << casenum+1 << ": " << result << endl;
	}

	return 0;
}
