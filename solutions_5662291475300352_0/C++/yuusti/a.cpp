// BEGIN CUT HERE
#ifdef _MSC_VER
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>
#include <unordered_map>
#include <agents.h>
#else
// END CUT HERE
#include <bits/stdc++.h>
// BEGIN CUT HERE
#endif
// END CUT HERE

#define FOR(i, a, b) for(int i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;

int main(){
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; ++cas){
		int n;
		cin >> n;
		vector<int> d, m;
		rep(i, n){
			int dd, hh, mm;
			cin >> dd >> hh >> mm;
			rep(j, hh){
				d.push_back(dd);
				m.push_back(mm + j);
			}
		}

		n = d.size();
		int ans = 0;
		if (n == 2){
			if (m[0] < m[1]){
				swap(m[0], m[1]);
				swap(d[0], d[1]);
			}
			ll r0 = 360 - d[0], r1 = 720 - d[1];
			ans = m[0] * r0 >= m[1] * r1;
		}

		printf("Case #%d: %d\n", cas, ans);
	}
}