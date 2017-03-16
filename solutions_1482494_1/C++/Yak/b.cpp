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

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI N; cin >> N;
		vector<UI> a(N), b(N); for(UI i: IR(0U, N)) { cin >> a[i] >> b[i]; }
		vector<UI> c(N);
		UI cur = 0, result = 0;
		while(1) {
			bool update;
			do {
				update = false;
				for(UI i: IR(0U,N)) {
					if(c[i] == 0 && b[i] <= cur) {
						cur += 2; c[i] = 2;
						++result; update = true;
					}
					if(c[i] == 1 && b[i] <= cur) {
						++cur; c[i] = 2;
						++result; update = true;
					}
				}
			} while(update);
			UI idx = N, val = 0;
			for(UI i: IR(0U,N)) {
				if(c[i] == 0 && a[i] <= cur) {
					if(idx == N) {
						idx = i; val = b[i];
					} else {
						if(val < b[i]) {
							val = b[i]; idx =i;
						}
					}
				}
			}
			if(idx != N) {
				++cur; ++c[idx]; ++result;
			} else break;
		}
		if(cur != 2*N) {
			cout << "Case #" << casenum+1 << ": Too Bad" << endl;
		} else {
			cout << "Case #" << casenum+1 << ": " << result << endl;
		}
	}

	return 0;
}
