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

bool match(ULL n, string s)
{
	REP(i, s.size()) {
		if(s[s.size()-i-1] != '?' && n%10 != s[s.size()-i-1]-'0') return false;
		n /= 10;
	}
	return true;
}

ULL absd(ULL n1, ULL n2) { return n1 > n2 ? n1 - n2 : n2 - n1; }

ULL dshift(ULL d, ULL num) { while(num-->0) d*=10; return d; }

pair<ULL, ULL> select(ULL c1, ULL j1, ULL c2, ULL j2, ULL c3, ULL j3)
{
	ULL rc = c1, rj = j1, rd = absd(c1, j1);
	if(rd > absd(c2, j2) ||
	   (rd == absd(c2, j2) && rc > c2) ||
	   (rd == absd(c2, j2) && rc == c2 && rj > j2)) {
		rd = absd(c2, j2); rc = c2; rj = j2;
	}
	if(rd > absd(c3, j3) ||
	   (rd == absd(c3, j3) && rc > c3) ||
	   (rd == absd(c3, j3) && rc == c3 && rj > j3)) {
		rd = absd(c3, j3); rc = c3; rj = j3;
	}
	return { rc, rj };
}

const ULL guard = 0xFFFFFFFFFFFFFFFFULL;
typedef vector<vector<pair<ULL,ULL>>> Table; // table[idx][type] -> (c,j)
enum REQ { CMAX, DMIN, JMAX };

pair<ULL, ULL> calc(UI n, REQ req, string c, string j, Table &table)
{
	if(table[n][req].first == guard) {
		if(n == c.size() - 1) {
			switch(req) {
			case CMAX:
				if(c[n] == '?') table[n][req].first = 9;
				else table[n][req].first = c[n]-'0';
				if(j[n] == '?') table[n][req].second = 0;
				else table[n][req].second = j[n]-'0';
				break;
			case DMIN:
				if(c[n] == '?') {
					if(j[n] == '?') {
						table[n][req].first = 0;
						table[n][req].second = 0;
					} else {
						table[n][req].first = j[n]-'0';
						table[n][req].second = j[n]-'0';
					}
				} else {
					if(j[n] == '?') {
						table[n][req].first = c[n]-'0';
						table[n][req].second = c[n]-'0';
					} else {
						table[n][req].first = c[n]-'0';
						table[n][req].second = j[n]-'0';
					}
				}
				break;
			case JMAX:
				if(c[n] == '?') table[n][req].first = 0;
				else table[n][req].first = c[n]-'0';
				if(j[n] == '?') table[n][req].second = 9;
				else table[n][req].second = j[n]-'0';
				break;
			}
		} else {
			switch(req) {
			case CMAX: {
				auto t = calc(n+1, req, c, j, table);
				if(c[n] == '?') table[n][req].first = t.first + dshift(9, c.size()-n-1);
				else table[n][req].first = t.first + dshift(c[n]-'0', c.size()-n-1);
				if(j[n] == '?') table[n][req].second = t.second + dshift(0, c.size()-n-1);
				else table[n][req].second = t.second + dshift(j[n]-'0', c.size()-n-1);
			}
				break;
			case DMIN: {
				auto tc = calc(n+1, CMAX, c, j, table);
				auto td = calc(n+1, DMIN, c, j, table);
				auto tj = calc(n+1, JMAX, c, j, table);
				if(c[n] == '?') {
					if(j[n] == '?') {
						tc.second += dshift(1, c.size()-n-1);
						tj.first  += dshift(1, c.size()-n-1);
					} else {
						td.first  += dshift(j[n]-'0', c.size()-n-1);
						td.second += dshift(j[n]-'0', c.size()-n-1);
						tc.first  += dshift(j[n]-'0'-(j[n]>'0'?1:0), c.size()-n-1);
						tc.second += dshift(j[n]-'0', c.size()-n-1);
						tj.first  += dshift(j[n]-'0'+(j[n]<'9'?1:0), c.size()-n-1);
						tj.second += dshift(j[n]-'0', c.size()-n-1);
					}
				} else {
					if(j[n] == '?') {
						td.first  += dshift(c[n]-'0', c.size()-n-1);
						td.second += dshift(c[n]-'0', c.size()-n-1);
						tc.first  += dshift(c[n]-'0', c.size()-n-1);
						tc.second += dshift(c[n]-'0'+(c[n]<'9'?1:0), c.size()-n-1);
						tj.first  += dshift(c[n]-'0', c.size()-n-1);
						tj.second += dshift(c[n]-'0'-(c[n]>'0'?1:0), c.size()-n-1);
					} else {
						tc.first  += dshift(c[n]-'0', c.size()-n-1);
						tc.second += dshift(j[n]-'0', c.size()-n-1);
						td.first  += dshift(c[n]-'0', c.size()-n-1);
						td.second += dshift(j[n]-'0', c.size()-n-1);
						tj.first  += dshift(c[n]-'0', c.size()-n-1);
						tj.second += dshift(j[n]-'0', c.size()-n-1);
					}
				}
				table[n][req] = select(tc.first, tc.second,
						               td.first, td.second,
						               tj.first, tj.second);
			}
				break;
			case JMAX: {
				auto t = calc(n+1, req, c, j, table);
				if(c[n] == '?') table[n][req].first = t.first + dshift(0, c.size()-n-1);
				else table[n][req].first = t.first + dshift(c[n]-'0', c.size()-n-1);
				if(j[n] == '?') table[n][req].second = t.second + dshift(9, c.size()-n-1);
				else table[n][req].second = t.second + dshift(j[n]-'0', c.size()-n-1);
			}
				break;
			}
		}
	}
	return table[n][req];
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		string c,j; cin >> c >> j;
		Table table(c.size(), vector<pair<ULL,ULL>>(3, { guard, guard }));
		auto result = calc(0, DMIN, c, j, table);
		cout << "Case #" << casenum+1 << ": " << setw(c.size()) << setfill('0') << result.first << ' '
		                                      << setw(c.size()) << setfill('0') << result.second << endl;
	}

	return 0;
}
