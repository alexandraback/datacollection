#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int R,N,M,K;

int count(int& v, int div){
	int ret = 0;
	while(v % div == 0) {
		v /= div;
		++ret;
	}
	return ret;
}

void collect(const vector<int> digits, int depth, int cur, multiset<int>& ms) {
	if (depth == digits.size()) {
		ms.insert(cur);
		return;
	}
	collect(digits, depth + 1, cur, ms);
	collect(digits, depth + 1, cur * digits[depth], ms);
}

void search(int count, const set<int>& gen, int count3, int count2) {
	vector<int> ans(count, 2);
	ll mv = 0;
	vector<int> digits(count);
	for (int i = 0; i < 10; ++i) {
		int c6 = rand() % (count3 + 1);
		int c3 = count3;
		int c2 = c3 + rand() % (count - count3 + 1);
		int c4 = c2 + rand() % (count - c2 + 1);
		int c8 = count;
		fill(digits.begin(), digits.begin() + c6, 6);
		fill(digits.begin() + c6, digits.begin() + c3, 3);
		fill(digits.begin() + c3, digits.begin() + c2, 2);
		fill(digits.begin() + c2, digits.begin() + c4, 4);
		fill(digits.begin() + c4, digits.begin() + c8, 8);
		multiset<int> my;
		collect(digits, 0, 1, my);
		ll val = 1;
		for (int g : gen) {
			int c = my.count(g);
			if (c == 0) {
				val = 0;
				break;
			}
			val *= c;
		}
		if (val > mv) {
			mv = val;
			ans = digits;
		}
	}

	for (int i = 0; i < count; ++i) {
		printf("%d", ans[i]);
	}
}

void solve() {
	scanf("%d %d %d %d", &R, &N, &M, &K);
	for (int r = 0; r < R; ++r) {
		int c5 = 0;
		int c7 = 0;
		set<int> s;
		int c3 = 0;
		int c2 = 0;
		for (int k = 0; k < K; ++k) {
			int v;
			scanf("%d", &v);
			c5 = max(c5, count(v, 5));
			c7 = max(c7, count(v, 7));
			s.insert(v);
			c3 = max(c3, count(v, 3));
			c2 = max(c2, count(v, 2));
		}
		int rest = N - c5 - c7;
		for (int i = 0; i < c5; ++i) {
			printf("5");
		}
		for (int i = 0; i < c7; ++i) {
			printf("7");
		}
		search(rest, s, c3, c2);
		printf("\n");
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d:\n", tc);
		solve();
	}
}
