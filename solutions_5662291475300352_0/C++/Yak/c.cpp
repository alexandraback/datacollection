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
		UI N; cin >> N;
		vector<UI> deg;
		vector<ULL> minute;
		ULL maxt = 0;
		for(auto i: IR(0U, N)) {
			UI deg_, num_; ULL minute_; cin >> deg_ >> num_ >> minute_;
			for(auto j: IR(0U, num_)) {
				deg.push_back(deg_);
				minute.push_back(minute_+j);
//cerr << deg_ << ',' << (720-deg_)*(minute_+j) << endl;
				maxt=max(maxt, (720-deg_)*(minute_+j));
			}
		}
//cerr << maxt << endl;
		vector<ULL> pos;
		for(auto i: IR(0U, deg.size())) {
			auto temp = (360-deg[i])*minute[i];
			while(temp <= maxt) {
				pos.push_back(temp);
				temp += minute[i];
			}
		}
		UI result = numeric_limits<UI>::max();
		sort(RNG(pos));
		for(auto t: pos) {
			UI temp = 0;
			for(auto i: IR(0U, deg.size())) {
				auto offset = (360-deg[i])*minute[i];
				if(t < offset) {
					++temp;
				} else {
					temp += (t - offset) / (360*minute[i]);
				}
			}
			result = min(result, temp);
		}
		cout << "Case #" << casenum+1 << ": " << result << endl;
	}

	return 0;
}
