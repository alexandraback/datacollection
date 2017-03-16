#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long ll;

ll gen(const vector<ll>& v, int K){
	ll ret = 0;
	for (ll c : v){
		ret *= K;
		ret += c;
	}
	return ret + 1;
}

int main(){
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";

		int K, C, S; cin >> K >> C >> S;
		if (S*C < K) cout << "IMPOSSIBLE" << endl;
		else{
			vector<ll> v;
			for (int i = 0; i < S*C; i++){
				v.push_back(i%K);
			}

			vector<ll> ans;

			for (int i = 0; i < S; i++){
				ans.push_back(gen(vector<ll>(v.begin() + (i*C), v.begin() + (i*C + C)), K));
			}

			sort(ans.begin(), ans.end());
			ans.erase(unique(ans.begin(), ans.end()), ans.end());

			for (ll a : ans) cout << a << ' ';

			cout << endl;
		}
	}
}