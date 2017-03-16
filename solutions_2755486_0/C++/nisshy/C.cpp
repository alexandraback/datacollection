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

typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for(int test = 1; test <= t; ++test) {
		int n;
		cin >> n;


		priority_queue<P, vector<P>, greater<P> > que;
		vector<int> nn(n), w(n), e(n), s(n), dd(n), dp(n), ds(n);
		for(int i = 0; i < n; ++i) {
			int d;
			cin >> d >> nn[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
			que.push(make_pair(d, i));
		}

		int ans = 0;
		int prev = -1;
		vector<int> wall_w, wall_e, next_height;
		vector<int> height(420, 0);
		vector<int> mid_height(420, 0);

		const int OFFSET = 205;

		while(!que.empty()) {
			const int day = que.top().first, num = que.top().second;
			que.pop();

			if(day != prev) {
				for(int i = 0; i < (int)wall_w.size(); ++i) {
					for(int j = wall_w[i]; j <= wall_e[i]; ++j)
						chmax(height[j + OFFSET], next_height[i]);

					for(int j = wall_w[i]; j < wall_e[i]; ++j)
						chmax(mid_height[j + OFFSET], next_height[i]);
				}

				wall_w.clear();
				wall_e.clear();
				next_height.clear();
				prev = day;
			}

			for(int i = w[num]; i <= e[num]; ++i) {
				if(height[i + OFFSET] < s[num]
				   || (i != e[num] && mid_height[i + OFFSET] < s[num])) {
					++ans;
					wall_w.push_back(w[num]);
					wall_e.push_back(e[num]);
					next_height.push_back(s[num]);
					break;
				}
			}

			if(--nn[num]) {
				w[num] += dp[num];
				e[num] += dp[num];
				s[num] += ds[num];
				que.push(make_pair(day + dd[num], num));
			}
		}

		cout << "Case #" << test << ": " << ans << endl;
	}

	return EXIT_SUCCESS;
}
