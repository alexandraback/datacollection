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

map<char, map<char, pair<bool,char>>> table = {
	{ '1', {
	  { '1', { true,  '1' } },
	  { 'i', { true,  'i' } },
	  { 'j', { true,  'j' } },
	  { 'k', { true,  'k' } }
	} },

	{ 'i', {
	  { '1', { true,  'i' } },
	  { 'i', { false, '1' } },
	  { 'j', { true,  'k' } },
	  { 'k', { false, 'j' } }
	} },

	{ 'j', {
	  { '1', { true,  'j' } },
	  { 'i', { false, 'k' } },
	  { 'j', { false, '1' } },
	  { 'k', { true,  'i' } },
	} },

	{ 'k', {
	  { '1', { true,  'k' } },
	  { 'i', { true,  'j' } },
	  { 'j', { false, 'i' } },
	  { 'k', { false, '1' } }
	} }
};

bool check(char c, const string &s, ULL &l, ULL &x, ULL L, ULL X)
{
	int xnum = 0;
	char cur = '1';
	bool cursgn = true;
	while(xnum < 5 && x < X) {
		auto next = table[cur][s[l]];
		cursgn = !(cursgn ^ next.first);
		cur = next.second;
		++l;
		if(l == L) {
			++x; ++xnum;
			l = 0;
		}
		if(cursgn && cur == c) return true;
	}
	return false;
}

bool check2(const string &s, ULL &l, ULL &x, ULL L, ULL X)
{
	char cur = '1';
	bool cursgn = true;
	X -= (X - x - 1) / 4 * 4;
	while(x < X) {
		auto next = table[cur][s[l]];
		cursgn = !(cursgn ^ next.first);
		cur = next.second;
		++l;
		if(l == L) {
			++x;
			l = 0;
		}
	}
	return cursgn && cur == '1';
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		ULL L, X; cin >> L >> X;
		string s; cin >> s;
		ULL l = 0, x = 0;
		bool result = check('i', s, l, x, L, X) && check('j', s, l, x, L, X) && check('k', s, l, x, L, X) && check2(s, l, x, L, X);
		if(result) {
			cout << "Case #" << casenum+1 << ": " << "YES" << endl;
		} else {
			cout << "Case #" << casenum+1 << ": " << "NO" << endl;
		}
	}

	return 0;
}
