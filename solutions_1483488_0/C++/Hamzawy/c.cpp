/*
 * c.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: AhmedHamza
 */

#include <ctime>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

//int power_dp[11][20];
//int digit_cnt_dp[2000001];

int digit_cnt(int n) {
//	int &ret = digit_cnt_dp[n];
//	if (ret)
//		return ret;
	int ret = 0;
	do {
		ret++;
		n /= 10;
	} while (n);
	return ret;
}

int power(int b, int p) {
	if (p == 0)
		return 1;
	if (p == 1)
		return b;
//	int &ret = power_dp[b][p];
//	if (ret != -1)
//		return ret;
	int x = power(b, p / 2);
//	return ret = (p & 1 ? x * x * b : x * x);
	return (p & 1 ? x * x * b : x * x);
}

bool fun(pii a, pii b) {
	swap(a.first, a.second);
	swap(b.first, b.second);
	return a < b;
}

int a, b;
inline bool val(int n) {
	return n >= a && n <= b;
}

#define SMALL_INPUT

int main() {
#ifdef SMALL_INPUT
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("c-small.out", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("c-large.in", "rt", stdin);
	freopen("c-large.out", "wt", stdout);
#endif

//	freopen("c.in", "rt", stdin);
//	cout<<50<<endl;
//	rep(i,50)
//		cout << 1 << " " << 2000000 << endl;
	//int st_time = clock();
//	freopen("c.txt", "wt", stdout);
//	mem(power_dp, -1);
	int n, m, p1, p2;
	vpii v;
	for (int i = 1; i < 2000001; ++i) {
		int len = digit_cnt(i);
		for (int j = 1; j < len; ++j) {
			p1 = power(10, j);
			p2 = power(10, len - j);
			n = i;
			m = i / p1 + (i % p1) * p2;
			if (n >= m || len != digit_cnt(m))
				continue;
			v.pb(mp(n, m));
//			cout << i << " " << n << " " << m << "\n";
//			cout << i << " " << n << " " << i / p1 << " " << (i % p1) * p2 << "\n";
		}
	}
//	vpii v2 = v;
//	sort(all(v2), fun);
//	cout << v.size() << endl;
//	return 0;

	set<pii> s;
	s.insert(all(v));
	v = vector<pii>(all(s));

	int tc;
	cin >> tc;
	rep(T,tc) {
		int ans = 0;
		cin >> a >> b;
		rep(i,v.size()) {
//			if (val(v[i].first) && val(v[i].second))
//				cout << v[i].first << " " << v[i].second<<endl;
			ans += val(v[i].first) && val(v[i].second);
		}
		cout << "Case #" << T + 1 << ": " << ans << endl;
	}

	//cerr << (double) (clock() - st_time) / CLOCKS_PER_SECOND << endl;
	return 0;
}

