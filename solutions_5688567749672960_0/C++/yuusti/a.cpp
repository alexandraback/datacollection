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

const int N = 1e6 + 10;
ll dist[N];

ll flip(ll x){
	if (x % 10 == 0) return -1;
	auto s = to_string(x);
	reverse(ALL(s));
	return stoll(s);
}

void naive_init(){
	MEMSET(dist, -1);

	queue<int> q;
	q.push(0);
	dist[0] = 0;

	auto f = [&](int x, int d){
		if (x < 0 || dist[x] >= 0) return;
		dist[x] = d;
		q.push(x);
	};

	while (!q.empty()){
		int x = q.front();
		q.pop();

		f(x + 1, dist[x] + 1);
		f(flip(x), dist[x] + 1);
	}
}

int main(){

	int T;
	cin >> T;
	naive_init();
	for (int cas = 1; cas <= T; ++cas){
		int n;
		cin >> n;
		printf("Case #%d: %lld\n", cas, dist[n]);
	}

}