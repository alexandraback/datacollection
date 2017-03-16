#include <bits/stdc++.h>

using namespace std;
#define ll long long


priority_queue<int> nums;
priority_queue<int> nums2;
ll high,low;

ll calc(ll res) {
	ll cur_max = nums.top();
	if (cur_max <= res)
		return (res-cur_max);
	else {
		if (cur_max <= 3)
			return -1;
	}
	priority_queue<int> nums3 = nums;
	nums.pop();
	nums.push(cur_max/2);
	nums.push(cur_max/2+cur_max%2);
	ll ans = calc(res-1);
	nums = nums3;
	nums.pop();
	nums.push(3);
	nums.push(cur_max-3);
	ans = max(ans,calc(res-1));
	return ans;
}

int main() {
	freopen("B-small-attempt3.in","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		while(!nums2.empty())
			nums2.pop();
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			int temp;
			cin >> temp;
			nums2.push(temp);
		}
		low = 0;
		high = 1000000000000;
		ll res;

		while (1) {
			nums = nums2;
			res = (low+high)/2;
			if (calc(res) < 0) {
				low = res+1;
				continue;
			} else {
				nums = nums2;
				if (calc(res-1) >= 0) {
					high = res-1;
					continue;
				} else {
					break;
				}
			}
		}
		cout << "Case #" << cnt << ": ";
		cout << res << endl;
	}
	return 0;
}
