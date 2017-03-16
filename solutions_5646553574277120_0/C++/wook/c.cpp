#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)
#define all(x) (x).begin(), (x).end()

int C, D, V;
vector<int> pre;

int with(int s) {
	int a = 0;
	for(int i=0; i<D; ++i) if(s&(1<<i)) a += pre[i];
	return a;
}
bool done(set<int> &S) {
	for(int i=1; i<=V; ++i) {
		if(S.count(i) == 0)
			return false;
	}
	return true;
}
vector<int> P = { 1, 2, 4, 8, 16 };

int go() {
	set<int> available;
	for(int s=0; s<(1<<D); ++s) available.insert( with(s) );

	int extra = 0;
	while(true)
	{
		if(done(available)) break;

		// extend one
		for(int i=1; i<=V; ++i) if(available.count(i) == 0) {
			set<int> a2 = available;
			for(int x : available) if(x + i <= V) a2.insert(x + i);

			if(done(a2))
				return ++ extra;
		}
		// impossible.
		for(int i : P) if(available.count(i) == 0) {
			set<int> a2 = available;
			for(int x : available) if(x + i <= V) a2.insert(x + i);
			available.swap(a2);
			++extra;
			break;
		}
	}
	return extra;
}

int main() {
	int T;
	cin >> T;

	for(int t=1; t<=T; ++t) {
		cin >> C >> D >> V;
		pre.resize(D);
		for(int i=0; i<D; ++ i) cin >> pre[i];

		printf("Case #%d: %d\n", t, go());
	}
	return 0;
}

