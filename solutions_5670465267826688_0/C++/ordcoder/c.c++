#include <bits/stdc++.h>
using namespace std;
#if defined(ILIKEGENTOO)
void E(){}template<class A,class...B>void E(A _,B...$){cerr<<' '<<_;E($...);}
#define E($...) E(#$,'=',$,'\n')
#else
#define E($...) ;
#endif
#define all(x) begin(x), end(x)

int table[5][5] = {{0, 0, 0, 0, 0},
{0, 1, 2, 3, 4},
{0, 2, -1, 4, -3},
{0, 3, -4, -1, 2},
{0, 4, 3, -2, -1},
};

int mult(int x, int y) {
	if (x < 0)
		if (y < 0)
			return table[-x][-y];
		else
			return -table[-x][y];
	else
		if (y < 0)
			return -table[x][-y];
		else
			return table[x][y];
}

void answer(bool ok) {
	if (ok) cout << "YES";
	else cout << "NO";
}

void solve() {
	int64_t l, x;
	string s;
	cin >> l >> x >> s;
	assert(l > 0 && x > 0);
	assert(s.size() == size_t(l));
	vector<int> nums(s.size());
	transform(all(s), begin(nums), [](char c){assert(c>='i'&&c<='k'); return c-'i'+2;});
	int fold = accumulate(all(nums), 1, mult);
	//for (auto v: nums) E(v);

	// because \forall y y^4==1
	int foldall = 1;
	for (int64_t i = x % 8; i > 0; --i)
		foldall = mult(foldall, fold);
	//E(fold, foldall);
	if (foldall != mult(2, mult(3, 4)))
		return answer(false);

	int run = 1;
	auto inf = numeric_limits<int64_t>::max();
	auto bestl = inf;
	for (int64_t i = 0; i < l; ++i) {
		int crun = run;
		for (int j = 0; j < 8; ++j) {
			if (crun == 2)
				bestl = min(bestl, j * l + i);
			crun = mult(fold, crun);
		}
		run = mult(run, nums[i]);
	}
	assert(run == fold);

	run = 1;
	auto bestr = inf;
	for (int64_t i = 0; i < l; ++i) {
		int crun = run;
		for (int j = 0; j < 8; ++j) {
			if (crun == 4)
				bestr = min(bestr, j * l + i);
			crun = mult(crun, fold);
		}
		run = mult(nums[l - 1 - i], run);
	}

	//E(bestl, bestr);
	return answer((bestl < inf) && (bestr < inf) && (bestl + bestr < l * x));
}

int main() {
	ios_base::sync_with_stdio(false);
	int tcase;
	cin >> tcase;
	for (int t = 0; t < tcase; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}

