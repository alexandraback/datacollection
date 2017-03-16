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

	int t;
	cin >> t;

	for(int test = 1; test <= t; ++test) {
		int x, y;
		cin >> x >> y;

		string ans;
		while(x != 0) {
			if(x > 0) {
				ans += "WE";
				--x;
			}
			else {
				ans += "EW";
				++x;
			}
		}

		while(y != 0) {
			if(y > 0) {
				ans += "SN";
				--y;
			}
			else {
				ans += "NS";
				++y;
			}
		}

		cout << "Case #" << test << ": " << ans << endl;
	}

	return EXIT_SUCCESS;
}
