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

void inc(vector<char> &v)
{
	++v[0];
	for(auto i : IR(0U, v.size())) {
		if(v[i] >= 10) {
			if(i+1 >= v.size()) { v.push_back(1); v[i]-=10; }
			else {
				++v[i+1];
				v[i] -= 10;
			}
		}
	}
}

void fixup(vector<char> &v)
{
	while(v.back() == 0) {
		v.pop_back();
	}
}

bool myless(const vector<char> &v1, const vector<char> &v2)
{
	if(v1.size() < v2.size()) return true;
	if(v1.size() > v2.size()) return false;
	for(auto i: IR(0U, v1.size())) {
		if(v1[v1.size()-i-1] < v2[v2.size()-i-1]) return true;
		if(v1[v1.size()-i-1] > v2[v2.size()-i-1]) return false;
	}
	return false;
}

void tovec(ULL N, vector<char> &v)
{
	v.clear();
	while(N > 0) {
		v.push_back(N % 10);
		N /= 10;
	}
}

ULL fromvec(const vector<char> &v)
{
	ULL ret = 0;
	for(auto i: IR(0U, v.size())) {
		ret *= 10;
		ret += v[v.size()-i-1];
	}
	return ret;
}

ULL rev(ULL n)
{
	vector<char> v;
	tovec(n, v);
	reverse(RNG(v));
	fixup(v);
	return fromvec(v);
}

vector<int> table(1000001);

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	set<int> buf1, buf2;
	table[1] = 1;
	buf1.insert(1);
	while(!buf1.empty()) {
		buf2.clear();
		for(auto val: buf1) {
			if(val+1<table.size()) {
				if(table[val+1]==0||table[val+1]>table[val]) {
					table[val+1]=table[val]+1;
					buf2.insert(val+1);
				}
			}
			auto revn = rev(val);
			if(revn+1<table.size()) {
				if(table[revn]==0||table[revn]>table[val]) {
					table[revn]=table[val]+1;
					buf2.insert(revn);
				}
			}
		}
		buf1 = buf2;
	}
	REP(casenum, cases) {
		ULL N; cin >> N;
		cout << "Case #" << casenum+1 << ": " << table[N] << endl;
	}

	return 0;
}
