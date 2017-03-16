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
		string s; cin >> s;
		vector<UI> cnt(26);
		vector<UI> result(10);
		for(char c: s) { ++cnt[c-'A']; }
		UI tmp;
		if(cnt['W'-'A']) {
			tmp = cnt['W'-'A'];
			result[2]+=tmp; cnt['T'-'A']-=tmp; cnt['W'-'A']-=tmp; cnt['O'-'A']-=tmp;
		}
		if(cnt['U'-'A']) {
			tmp = cnt['U'-'A'];
			result[4]+=tmp; cnt['F'-'A']-=tmp; cnt['O'-'A']-=tmp; cnt['U'-'A']-=tmp; cnt['R'-'A']-=tmp;
		}
		if(cnt['X'-'A']) {
			tmp = cnt['X'-'A'];
			result[6]+=tmp; cnt['S'-'A']-=tmp; cnt['I'-'A']-=tmp; cnt['X'-'A']-=tmp;
		}
		if(cnt['Z'-'A']) {
			tmp = cnt['Z'-'A'];
			result[0]+=tmp; cnt['Z'-'A']-=tmp; cnt['E'-'A']-=tmp; cnt['R'-'A']-=tmp; cnt['O'-'A']-=tmp;
		}
		if(cnt['R'-'A']) {
			tmp = cnt['R'-'A'];
			result[3]+=tmp; cnt['T'-'A']-=tmp; cnt['H'-'A']-=tmp; cnt['R'-'A']-=tmp; cnt['E'-'A']-=tmp*2;
		}
		if(cnt['S'-'A']) {
			tmp = cnt['S'-'A'];
			result[7]+=tmp; cnt['S'-'A']-=tmp; cnt['E'-'A']-=tmp*2; cnt['V'-'A']-=tmp; cnt['N'-'A']-=tmp;
		}
		if(cnt['V'-'A']) {
			tmp = cnt['V'-'A'];
			result[5]+=tmp; cnt['F'-'A']-=tmp; cnt['I'-'A']-=tmp; cnt['V'-'A']-=tmp; cnt['E'-'A']-=tmp;
		}
		if(cnt['H'-'A']) {
			tmp = cnt['H'-'A'];
			result[8]+=tmp; cnt['E'-'A']-=tmp; cnt['I'-'A']-=tmp; cnt['G'-'A']-=tmp; cnt['H'-'A']-=tmp; cnt['T'-'A']-=tmp;
		}
		if(cnt['O'-'A']) {
			tmp = cnt['O'-'A'];
			result[1]+=tmp; cnt['O'-'A']-=tmp; cnt['N'-'A']-=tmp; cnt['E'-'A']-=tmp;
		}
		if(cnt['I'-'A']) {
			tmp = cnt['I'-'A'];
			result[9]+=tmp; cnt['N'-'A']-=tmp*2; cnt['I'-'A']-=tmp; cnt['E'-'A']-=tmp;
		}
		for(auto c: cnt) { if(c) cerr << "ERROR:" << endl; }
		cout << "Case #" << casenum+1 << ": ";
		REP(i, 10) {
			REP(j, result[i]) { cout << i; }
		}
		cout << endl;
	}

	return 0;
}
