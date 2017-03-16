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

void outbin(ostream &os, UI i)
{
	string s;
	while(i != 0) {
		s.push_back(i%2+'0');
		i>>=1;
	}
	reverse(RNG(s));
	os << s;
}

ULL convbase(UI i, ULL base)
{
	ULL result = 0, factor = 1;
	while(i != 0) {
		if(i%2) {
			result += factor;
		}
		factor *= base;
		i>>=1;
	}
	return result;
}

ULL check(UI i, UI base)
{
	ULL ii = convbase(i, base);
	for(auto j: IR<ULL>(2, sqrt(ii)+1)) {
		if((ii%j)==0 && ii!=j) return j;
	}
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		UI N, J;
		cin >> N >> J;
		UI NN = 1<<N;
		vector<bool> bits(NN+1);
// sieve in base 2
		UI e = sqrt(NN) + 1;
		for(auto i: IR(2U, e)) {
			for(UI idx = i; idx <= NN; idx+=i) {
				bits[idx] = true;
			}
		}
		cout << "Case #" << casenum+1 << ":" << endl;
		UI count = 0;
		array<int, 11> div;
		for(auto i: IR(NN/2+1, NN+1)) {
			if(bits[i] && i%2) { // not prime
//cerr << i << endl;
				bool ok = true;
				for(auto j: IR(2, 11)) {
					div[j] = check(i, j);
					if(!div[j]) {
						ok = false;
						break;
					}
				}
				if(ok) {
					outbin(cout, i);
					for(auto j: IR(2, 11)) {
						cout << ' ' << div[j];
					}
					cout << endl;
					++count;
					if(count >= J) break;
				}
			}
		}
	}

	return 0;
}
