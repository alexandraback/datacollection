#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector <string> a1, a2;
ll N;
ll check_set(ll m, ll pos){return (m & (1LL << pos));}

ll memo[17][(1LL << 16)];

ll f(ll n, ll m){
	if (n == N){
		//~ cout << m << endl;
		return 0;
	}
	if (memo[n][m] != -1) return memo[n][m];
	
	ll mx = 0;
	for (ll i = 0; i < N; i++){
		if (check_set(m, i) == 0){
			ll pos1 = 0, pos2 = 0;
			for (ll j = 0; j < N; j++)
				if (check_set(m, j) && a1[j] == a1[i]) pos1 = 1;
			for (ll j = 0; j < N; j++)
				if (check_set(m, j) && a2[j] == a2[i]) pos2 = 1;
				
			if (pos1 == 1 && pos2 == 1)	mx = max(mx, f(n + 1, m | (1LL << i)) + 1);
			else mx = max(mx, f(n + 1, m | (1LL << i)));
		}
	}
	return memo[n][m] = mx;
}
int main()
{
	int test; cin >> test;
	for (int t = 1; t <= test; t++){
		a1.clear();
		a2.clear();
		for (int i = 0; i < 17; i++)
			for (int j = 0; j < (1LL << 16); j++) memo[i][j] = -1;
		
		set<string> s;
		int k; cin >> k;
		N = k;
		for (int i = 0; i < k; i++){
			string a, b; cin >> a >> b;
			a1.push_back(a);
			a2.push_back(b);
		}		
		cout << "Case #" << t << ": " << f(0LL, 0LL) << endl;
	}
	return 0;
}
