#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;

typedef long long ll;

int cnt(ll n){
	int ret = 0;
	while (n){
		ret++;
		n /= 10;
	}
	return ret;
}

map<ll, ll> M;

ll f(ll n){
	if (M.count(n)) return M[n];

	if (n <= 10) return M[n] = n;
	if (n % 10 == 0) return M[n] = f(n - 1) + 1;
	ll res = n;

	string str = to_string(n);
	reverse(str.begin(), str.end());
	ll m = stoll(str);

	if (m < n && cnt(n)==cnt(m)) res = min(res, f(m) + 1);

	ll det = 10;
	while (n >= det){
		ll g = n - (n%det) + 1;
		if (g < n){
			res = min(res, f(g) + (n - g));
		}
		det *= 10;
	}

	if (m == n){
		int tmp = (cnt(n) - 1) / 2;
		int d = 1;
		for (int i = 0; i < tmp; i++) d *= 10;
		res = min(res, f(n - d) + d);
	}
	return M[n] = res;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		ll n;
		cin >> n;
		cout << f(n) << endl;
		M.clear();
	}
}