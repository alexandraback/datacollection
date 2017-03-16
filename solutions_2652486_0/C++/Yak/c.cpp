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
		cout << "Case #" << casenum+1 << ":" << endl;
		UI R,N,M,K; cin >> R >> N >> M >> K;
		REP(i, R) {
			vector<UI> pr(K); for(auto &val : pr) { cin >> val; }
			int mc2 = 0, mc3 = 0, mc5 = 0;
			vector<UI> dc2(7);
			for(auto val : pr) {
				int c2 = 0, c3 = 0, c5 = 0;
				while(val % 2 == 0) { ++c2; val /= 2;	}
				while(val % 3 == 0) { ++c3; val /= 3;	}
				while(val % 5 == 0) { ++c5; val /= 5;	}
				++dc2[c2];
				mc2 = max(mc2, c2);
				mc3 = max(mc3, c3);
				mc5 = max(mc5, c5);
			}
			REP(j, mc3) { cout << 3; }
			REP(j, mc5) { cout << 5; }
			int p2 = 3 - mc3 - mc5;
			int c4 = 0;
			if(dc2[6]) c4 = 3;
			else if(dc2[5]) c4 = 2;
			else if(dc2[4]) c4 = 2; //
			else if(dc2[3]) c4 = 1; //
			else if(dc2[2]) {
				if(p2 == 1) c4 = 1; //
				else if(dc2[1] == 0) c4 = 1;
			}
			REP(j, c4) { cout << 4; }
			REP(j, 3-mc3-mc5-c4) { cout << 2; }
			cout << endl;
		}
	}

	return 0;
}
