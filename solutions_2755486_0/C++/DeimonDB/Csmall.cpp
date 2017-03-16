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

struct Tribe {
	int d, n, w, e, s, dd, dp, ds;
};
struct Attack {
	int d, w, e, s;
	void print() {
		printf("d = %d, w = %d, e = %d, s = %d\n", d, w, e, s);
	}
};
struct Update {
	int w, e, s;
};

bool cmp(Attack a, Attack b) {
	return a.d < b.d;
}
const int geser = 200;
Tribe tribe[10];
vector<Attack> attacks;
int wall[1000];

bool serang(Attack &a) {
	FOR(i, a.w, a.e-1) {
		if (wall[i + geser] < a.s) return true;
	}
	return false;
}

void fix(Update u) {
	FOR(i, u.w, u.e - 1) {
		wall[i+geser] = max(wall[i+geser], u.s);
	}
}
inline void solve(int tc) {
	memset(wall, 0, sizeof wall);
	attacks.clear();
	int N;
	scanf("%d", &N);
	REP(i, N) {
		Tribe &x = tribe[i];
		scanf("%d %d %d %d %d %d %d %d", &x.d, &x.n, &x.w, &x.e, &x.s, &x.dd, &x.dp, &x.ds);
		REP(j, x.n) {
			attacks.PB((Attack){x.d + (j * x.dd), x.w + (j * x.dp), x.e + (j * x.dp), x.s + (j * x.ds)});
		}
	}
	sort(attacks.begin(), attacks.end(), cmp);
	int bts = SZ(attacks);
	int res = 0;
	queue <Update> update_queue;
	int end;
	for (int i = 0; i < bts; i = end) {
		for (end = i+1; end < bts && attacks[end].d == attacks[i].d; end++);
		for (int j = i; j < end; j++) {
			if (serang(attacks[j])) {
				//attacks[j].print();
				res++;
				update_queue.push((Update){attacks[j].w, attacks[j].e, attacks[j].s});
			}
		}
		while(!update_queue.empty()) {
			fix(update_queue.front());
			update_queue.pop();
		}
	}
	printf("Case #%d: %d\n", tc, res);
}
int main() {
	int T;
	scanf("%d", &T);
	REP(i, T) solve(i+1);
	return 0;
}
