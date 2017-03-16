#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define ms(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> pt;

const int inf = 1<<30;
const int N = 1<<17;

char str[100];
string key, target, ss;
int up, down, k, l, s, best;

void check() {
	str[k] = 0;
	int cur = 0;
	for (int i = 0; i + l <= s; i++) {
		int len = 0;
		while (len < l && str[i + len] == target[len])
			len++;
		if (len == l) {
			up++;
			cur++;
		}
	}
	best = max(best, cur);
}

void go(int p) {
	if (p == s) {
		down++;
		check();
	} else {
		for (int i = 0; i < k; i++) {
			str[p] = key[i];
			go(p + 1);
		}
	}
}

int main() {
	freopen("y.in", "r", stdin);
	freopen("y.out", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cin >> k >> l >> s >> key >> target;
		up = down = best = 0;
		go(0);
		cerr << up << " " << down << endl;
		printf("Case #%d: %.6lf\n", test, best - up*1.0/down);
	}

	return 0;
}