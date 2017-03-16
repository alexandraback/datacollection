#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int OO = 1e9;
int c, d, v;

char memo[31][31];
bool solve(int idx, int rem, int msk) {
	if (rem <= 0)
		return (rem == 0);
	if (idx > v)
		return 0;
	char &ret = memo[idx][rem];
	if (ret != -1)
		return ret;
	bool ret1 = solve(idx + 1, rem, msk), ret2 = 0;
	if ((msk >> idx) & 1)
		ret2 = solve(idx + 1, rem - idx, msk);
	ret = ret1 | ret2;
	return ret1 | ret2;
}

bool check(int msk) {
	memset(memo, -1, sizeof memo);
	for (int i = 1; i <= v; ++i)
		if (!solve(1, i, msk))
			return 0;
	return 1;
}

int bt(int idx, int msk, int curRet) {
	if (idx > v || curRet == 5)
		return check(msk) ? 0 : OO;
	int ret1 = bt(idx + 1, msk, curRet), ret2 = OO;
	if (!((msk >> idx) & 1))
		ret2 = 1 + bt(idx + 1, (1 << idx) | msk, curRet + 1);
	return min(ret1, ret2);
}

int main() {
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	int t;
	cin >> t;
	for (int tst = 1; tst <= t; ++tst) {
		cin >> c >> d >> v;
		int val, msk = 0;
		for (int i = 0; i < d; ++i)
			cin >> val, msk |= (1 << val);
		cout << "Case #" << tst << ": " << bt(1, msk, 0) << endl;
	}
	return 0;
}
