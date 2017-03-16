#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
#define rep(i, n) for(int i = 0; i < n; ++i)

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

struct state {
	vector<int> cnt;
	void init() {cnt = vector<int>(26, 0);}
	state() {
		cnt = vector<int>(26, 0);
	}
	state(const state &b) {
		cnt = b.cnt;
	}
	state operator - (const state &b) const {
		state ans;
		ans.init();
		rep(i, sz(cnt)) ans.cnt[i] = cnt[i] - b.cnt[i];
		return ans;
	}
	bool operator < (const state &b)const {
		return cnt < b.cnt;
	}
	bool operator == (const state &b) const {
		return cnt == b.cnt;
	}
	bool operator != (const state &b) const {
		return cnt != b.cnt;
	}
} dig[10], cur, beg;

char s[10000];
map<state, int> prv;
set<state> good;

bool go(state from) {
	if (good.find(from) != good.end()) return true;
	rep(i, 10) {
		bool smaller = false;
		rep(j, 26)
		if (from.cnt[j] < dig[i].cnt[j]) {
			smaller = true;
			break;
		}
		if (smaller) continue;
		state curState = from - dig[i];
		if (go(curState)) {
			prv[from] = i;
			return true;
		}
	}
	return false;
}

void solve() {
	scanf("%s", s);
	cur.init();
	for(int i = 0; s[i]; ++i) ++cur.cnt[s[i] - 'A'];
	if (go(cur)) {
		vector<int> nums;
		while (cur != beg) {
			int number = prv[cur];
			nums.push_back(number);
			cur = cur - dig[number];
		}
		sort(nums.begin(), nums.end());
		rep(i, sz(nums)) printf("%d", nums[i]);
		printf("\n");
	}
}

int main() {
	int ntest;
	scanf("%d", &ntest);
	beg.init();
	good.insert(beg);
	rep(i, 10) {
		dig[i].init();
		rep(j, sz(digits[i])) ++dig[i].cnt[digits[i][j] - 'A'];
	}
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}