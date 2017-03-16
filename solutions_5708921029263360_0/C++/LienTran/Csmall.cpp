#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
#define rep(i, n) for(int i = 0, _ = (n); i < _; ++i)
#define ufor(i, a, b) for(int i = (a), _ = (b); i <= _; ++i)
#define dfor(i, a, b) for(int i = (a), _ = (b); i >= _; --i)

struct pet {
    int a, b, c;
    pet(int a, int b, int c) : a(a), b(b), c(c){}
    bool operator < (const pet &x) const {
        if (a != x.a) return a < x.a;
        if (b != x.b) return b < x.b;
        return c < x.c;
    }
    int code1() {
        return a * 16 + c;
    }
    int code2() {
        return b * 4 + c;
    }
    int code3() {
        return a * 16 + b * 4;
    }
    int code() {
        return a * 16 + b * 4 + c;
    }
};

int cnt[10000];

void solve() {
    memset(cnt, 0, sizeof cnt);
    int J, S, P, K;
    scanf("%d%d%d%d", &J, &P, &S, &K);
    set<pet> v;
    vector<pet> order;
    ufor(i, 1, J) ufor(j, 1, P) ufor(k, 1, S)
        v.insert(pet(i, j, k));
    memset(cnt, 0, sizeof cnt);
    while (!v.empty()) {
        pet best = pet(0, 0, 0);
        int cntBest = 10000;
        for(auto p : v) {
            int cur = cnt[p.code1()];
            cur = max(cur, cnt[p.code2()]);
            cur = max(cur, cnt[p.code3()]);
            if (cntBest > cur) {
                cntBest = cur;
                best = p;
            }
        }
        if (cntBest >= K) break;
        v.erase(best);
        ++cnt[best.code1()];
        ++cnt[best.code2()];
        ++cnt[best.code3()];
        order.push_back(best);
    }
    printf("%d\n", sz(order));
    //for(auto p : order) printf("%d %d %d\n", p.a, p.b, p.c);
}

int main() {
    freopen("in", "r", stdin);
    freopen("outSmall", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
