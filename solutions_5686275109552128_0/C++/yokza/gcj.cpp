#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define UPPER_BOUND 9

int with_step9(vector<int> nums) {
	int ans = UPPER_BOUND, penalty = 0;
	for(int num = UPPER_BOUND; num >= 0; num--) {
		if(!nums[num]) continue;
		ans = min(ans, num + penalty);
		if(num == 9) {
			penalty += nums[num];
			nums[3] += nums[num];
			nums[6] += nums[num];
			continue;
		}
		penalty += nums[num];
		nums[num>>1] += nums[num];
		nums[num-(num>>1)] += nums[num];
	}
	return ans;
}

int with_step(vector<int> nums) {
	int ans2 = UPPER_BOUND;
	if(nums[9]) ans2 = with_step9(nums);
	int ans = UPPER_BOUND, penalty = 0;
	for(int num = UPPER_BOUND; num >= 0; num--) {
		if(!nums[num]) continue;
		ans = min(ans, num + penalty);
		penalty += nums[num];
		nums[num>>1] += nums[num];
		nums[num-(num>>1)] += nums[num];
	}
	return min(ans, ans2);
}

void solve_case(int numc) {
	int n;
	cin >> n;
	vector<int> nums(UPPER_BOUND + 2, 0);
	int x;
	for(int i=0;i<n;i++) {
		cin >> x;
		nums[x]++;
	}
	int ts=0, ans=UPPER_BOUND;
	for(int steps = 0; steps <= UPPER_BOUND; steps++) {
		ans = min(ans, with_step(nums) + steps);
		for(int i=0;i<UPPER_BOUND;i++) nums[i] = nums[i+1];
	}

	cout << "Case #" << numc << ": ";
	cout << ans << endl;
}

int main(){
	int cases;
	cin >> cases;
	for(int i=1;i<=cases;i++) {
		solve_case(i);
	}
	return 0;
}