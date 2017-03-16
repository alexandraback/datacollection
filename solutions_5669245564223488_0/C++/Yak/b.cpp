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

struct spec
{
	char b, e;
};

enum { ALL, BEGIN, END, WITHIN };
bool check(const vector<string> &v, vector<vector<int>> &count_)
{
	vector<vector<int>> count(26, vector<int>(4));
	vector<int> diff;
	int idx = -1;
	for(auto &i : v) {
		++idx;
		if(i.size() == 1) {
			++count[i[0]-'a'][ALL];
			++count_[i[0]-'a'][ALL];
		} else if(i.size() == 2) {
			if(i[0] == i[1]) {
				++count[i[0]-'a'][ALL];
				++count_[i[0]-'a'][ALL];
			} else {
				++count[i[0]-'a'][BEGIN];
				++count[i[1]-'a'][END];
				++count_[i[0]-'a'][BEGIN];
				++count_[i[1]-'a'][END];
				diff.push_back(idx);
			}
		} else {
			size_t b = 0, e = i.size() - 1;
			while(i[0] == i[b] && b < i.size() - 1) ++b;
			while(i[i.size()-1] == i[e] && e > 0) --e;
			if(e == 0 && b == i.size() - 1) {
				++count[i[0]-'a'][ALL];
			} else {
				++count[i[0]-'a'][BEGIN];
				++count[i[i.size()-1]-'a'][END];
				char prev = ' ';
				for(size_t j = b; j <= e; ++j) {
					if(prev != i[j]) {
						++count[i[j]-'a'][WITHIN];
						prev = i[j];
					}
				}
			}
			if(i[0] == i[i.size()-1]) {
				++count_[i[0]-'a'][ALL];
			} else {
				++count_[i[0]-'a'][BEGIN];
				++count_[i[i.size()-1]-'a'][END];
				diff.push_back(idx);
			}
		}
	}
//cout << diff.size() << endl;
	for(size_t i = 0; i < 26; ++i) {
//cout << count[i][ALL] << ':' << count[i][BEGIN] << ':' << count[i][END] << ':' << count[i][WITHIN] << endl;
//cout << count_[i][ALL] << ':' << count_[i][BEGIN] << ':' << count_[i][END] << endl;
		if(count_[i][BEGIN] > 1) return false;
		if(count_[i][END] > 1) return false;
		if(count[i][WITHIN] > 1 || (count[i][WITHIN] && (count[i][ALL] || count[i][BEGIN] || count[i][END]))) return false;
	}
//cout << "TH1" << endl;
	for(auto i : IR<int>(0, diff.size())) {
		vector<int> used(v.size());
		function<bool(int)> dfs = [&](int cur){
			used[cur] = 1;
			for(auto j: IR<int>(0, diff.size())) {
				if(v[cur][v[cur].size()-1] == v[diff[j]][0]) {
					if(used[diff[j]]) return false;
					return dfs(diff[j]);
				}
			}
			return true;
		};
		if(!dfs(diff[i])) return false;
	}
	return true;
}

ULL modulo = 1000000007;

ULL calc(ULL v, ULL p)
{
	while(p) {
		v = (v * p) % modulo;
		--p;
	}
	return v;
}

int main(void)
{
	ios_base::sync_with_stdio(false);

	UI cases; cin >> cases;
	REP(casenum, cases) {
		int N; cin >> N;
		vector<string> v(N); for(auto &val : v) { cin >> val; }
		vector<vector<int>> count(26, vector<int>(4));
		ULL result = 0;
		if(check(v, count)) {
			result = 1;
			int con = N - 1;
			for(auto &vv : count) {
				result = calc(result, vv[ALL]);
				if(vv[ALL]) {
					con -= (vv[ALL] + vv[BEGIN] + vv[END] - 1);
				} else if(vv[BEGIN] && vv[END]) --con;
			}
			assert(con >= 0);
//cout << "con: " << con << endl;
			result = calc(result, con+1);
		} else {
//			cout << "FALSE" << endl;
		}
		cout << "Case #" << casenum+1 << ": " << result << endl;
	}

	return 0;
}
