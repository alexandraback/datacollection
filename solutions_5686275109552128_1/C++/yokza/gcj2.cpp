#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define UPPER_BOUND 1000

int solved(vector<int>& nums, int burned) {
	int splits = 0;
	for(int num = burned + 1; num <= UPPER_BOUND; num++) {
		if (!nums[num]) continue;
		splits += nums[num] * (ceil(1. * num / burned) - 1);
	}
	return splits;
}

void solve_case(int ncase) {
	int n;
	cin >> n;
	vector<int> nums(UPPER_BOUND + 2, 0);
	int x;
	for(int i=0;i<n;i++) {
		cin >> x;
		nums[x]++;
	}
	int ts=0, ans = UPPER_BOUND;
	for(int ub = 1; ub<=UPPER_BOUND; ub++) {
		ans = min(ans, ub + solved(nums, ub));
	}
	cout << "Case #" << ncase << ": " << ans << endl;
}

int main() {
	int cases;
	cin >> cases;
	for(int i=1;i<=cases;i++) {
		solve_case(i);
	}
	return 0;
}