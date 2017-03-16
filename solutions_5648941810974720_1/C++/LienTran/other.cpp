#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
#define rep(i, n) for(int i = 0; i < n; ++i)

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
typedef pair<int, char> IC;
vector< pair<int, char> > order;

char s[10000];
int cnt[256];

void solve() {
	scanf("%s", s);
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; s[i]; ++i) ++cnt[s[i]];
	vector<int> nums;
	rep(i, sz(order)) {
		int dig = order[i].first;
		char what = order[i].second;
		while (cnt[what] > 0) {
			nums.push_back(dig);
			rep(j, sz(digits[dig])) --cnt[digits[dig][j]];	
		}
		
	}
	sort(nums.begin(), nums.end());
	rep(i, sz(nums)) printf("%d", nums[i]);
	printf("\n");
}

int main() {
	order.push_back(IC(0, 'Z'));
	order.push_back(IC(2, 'W'));
	order.push_back(IC(4, 'U'));
	order.push_back(IC(6, 'X'));
	order.push_back(IC(7, 'S'));
	order.push_back(IC(8, 'G'));
	order.push_back(IC(3, 'R'));
	order.push_back(IC(5, 'F'));
	order.push_back(IC(1, 'O'));
	order.push_back(IC(9, 'E'));
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}