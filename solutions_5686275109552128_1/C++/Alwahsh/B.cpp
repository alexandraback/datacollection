#include <bits/stdc++.h>

using namespace std;
#define ll long long

int num;
vector <ll> nums;
ll high,low;

ll calc(ll res) {
	ll sol = res;
	for (int i = 0; i < num; i++) {
		sol+= nums[i]/res;
		if (nums[i] % res == 0)
			sol--;
	}
	return sol;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("large.txt","w",stdout);
	int t;
	cin >> t;
	for (int cnt = 1; cnt <= t; cnt++) {
		cin >> num;
		nums.resize(num);
		high = 1;
		for (int i = 0; i < num; i++) {
			cin >> nums[i];
			high = max(high,nums[i]);
		}
		if (high <= 3) {
			cout << "Case #" << cnt << ": ";
			cout << high << endl;
			continue;
		}
		ll res = high;
		for (int i = 1; i < 1004; i++) {
			res = min(res,calc(i));
		}
		cout << "Case #" << cnt << ": ";
		cout << res << endl;
	}
	return 0;
}
