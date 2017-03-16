#include <cstring>
#include <string.h>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <valarray>
#include <memory.h>
#include <climits>

using namespace std;

vector<long long> all;

long long toL(const string &s) {
	long long res = 0;
	for(int i = 0; i < (int)s.size(); ++i)
		res *= 10, res += s[i] - '0';
	return res;
}

bool pal(long long n) {
	long long tmp = n, r = 0;
	while(n)
		r *= 10, r += n % 10, n /= 10;
	return r == tmp;
}

void add(const string &s) {
	long long res = toL(s);
	res *= res;
	if(pal(res)) {
		all.push_back(res);
	}
	return;
}

void gen(string s, int n) {
	if((int)s.size() == n) {
		if(s[0] != '0')
			add(s);
		return;
	}
	char c;
	for(int i = 0; i < 10; ++i) {
		c = '0' + i;
		gen(c + s + c, n);
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif

	for(int i = 1; i <= 7; ++i) {
		if(i & 1) {
			for(int j = 0; j < 10; ++j) {
				gen(string(1, '0' + j), i);
			}
		}else {
			gen("", i);
		}
	}
	sort(all.begin(), all.end());
	int t;
	long long a, b, res;
	scanf("%d", &t);
	for(int tst = 1; tst <= t; ++tst) {
		scanf("%lld %lld", &a, &b);
		res = 0;
		for(int i = 0; i < (int)all.size(); ++i) {
			res += (all[i] >= a && all[i] <= b);
		}
		printf("Case #%d: %lld\n", tst, res);
	}

	return 0;
}
