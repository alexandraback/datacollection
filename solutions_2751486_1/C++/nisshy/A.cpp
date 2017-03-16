#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define lengthof(array) (sizeof(array) / sizeof(*array))
#define dump(a) (cerr << (#a) << " = " << (a) << endl)
#define FOR(it,c) for(__typeof((c).begin())it=(c).begin(); it!=(c).end();++it)
#define RFOR(it,c) for(__typeof((c).rbegin())it=(c).rbegin(); it!=(c).rend();++it)

template<class T> inline void chmax(T& a, const T& b) { if(b > a) a = b; }
template<class T> inline void chmin(T& a, const T& b) { if(b < a) a = b; }

template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os << '(' << p.first << ", " << p.second << ')';
	return os;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
	return os;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	bool is_vowel[255] = {};
	is_vowel['a'] = true;
	is_vowel['e'] = true;
	is_vowel['i'] = true;
	is_vowel['o'] = true;
	is_vowel['u'] = true;

	int t;
	cin >> t;

	for(int test = 1; test <= t; ++test) {
		string s;
		int l;
		cin >> s >> l;

		int n = (int)s.size();
		vector<int> cnt(n + 1, 0);
		for(int i = 0; i < n; ++i)
			if(!is_vowel[s[i]])
				cnt[i + 1] = cnt[i] + 1;

		vector<pair<int, int> > end;
		for(int i = 0; i < n; ++i)
			if(cnt[i + 1] >= l)
				end.push_back(make_pair(i - l + 1, i));

		long long ans = 0;
		int num = (int)end.size();
		int j = 0;
		for(int i = 0; i < n; ++i) {
			while(j < num && end[j].first < i)
				++j;

			if(j != num)
				ans += n - end[j].second;
		}

		cout << "Case #" << test << ": " << ans << endl;
	}

	return EXIT_SUCCESS;
}
