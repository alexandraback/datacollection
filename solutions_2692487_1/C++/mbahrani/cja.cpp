#include<iostream>
#include<algorithm>
#define MN (1000 * 1000 + 5)

typedef long long ll;

using namespace std;

ll arr[MN], num, a;

ll solve(ll ind, ll size);

int main(){
	ll T, ans;
	cin >> T;
	for(ll tt = 0; tt < T; tt++){
		ans = 0;
		cin >> a >> num;
		for(ll i = 0; i < num; i++){
			cin >> arr[i];
		}
		
		if(a == 1){
			cout << "Case #" << tt + 1 << ": " << num << endl;
			continue;
		}
		sort(arr, arr+num);
		cout << "Case #" << tt + 1 << ": " << solve(0, a) << endl;
	}
	return 0;
}

ll solve(ll ind, ll size){
	if(ind >= num)
		return 0;
	if(arr[ind] < size){
		return solve(ind + 1, size + arr[ind]);
	}
	else{
		return min(num - ind, solve(ind, size + size - 1) + 1);
	}
}
