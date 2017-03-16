#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long int
#define endl '\n'

ll arr[250];

ll pow(ll a, ll p){
	if (p == 0) return 1;
	for (ll i = 0; i < p-1; i++)
		a *= a;
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T;
	cin >> T;
	ll Case = 1;
	for (ll i = 0; i < 250; i++){
		arr[i] = i;
	}
	while (T--){
		ll K, C, S;
		cin >> K >> C >> S;
		if ((K/C + (K%C > 0)) > S){
			cout << "Case #" << Case << ": IMPOSSIBLE\n";
			Case++;
			continue;
		}
		cout << "Case #" << Case << ":";
		ll cur = 0;
		ll start = 0;
		while (cur < S){
			ll sum = 0;
			ll cnt = 0;
			for (ll i = start; i < start+min(K, C) && i < K; i++){
				ll a = i % K;
				sum += arr[K-a-1]*pow(K, cnt);
				cnt++;
			}
			cout << " " << sum+1;
			cur += C;
			start += min(K, C);
		}
		cout << endl;
		Case++;
	}
}