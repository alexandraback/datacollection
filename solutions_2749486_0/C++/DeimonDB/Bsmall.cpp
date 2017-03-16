#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())

inline void solve(int tc) {
	int X, Y;
	scanf("%d %d", &X, &Y);
	printf("Case #%d: ", tc);
	if (X < 0) {
		REP(i, abs(X)) {
			printf("EW");
		}
	}
	else {
		REP(i, abs(X)) {
			printf("WE");
		}
	}
	if (Y < 0) {
		REP(i, abs(Y)) {
			printf("NS");
		}
	}
	else {
		REP(i, abs(Y)) {
			printf("SN");
		}
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
