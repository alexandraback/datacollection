#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int T, c, s, k;

int main(){
	freopen("D-small-attempt2.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> T;
	for(int te = 1; te <= T; te++){
		printf("Case #%d:", te);
		cin >> k >> c >> s;
		if(k > c * s) { printf(" IMPOSSIBLE\n"); continue; }
		int t = 0; vector<ll> ans;
		for(; t < k; ){
			ll now = 0;
			for(int i = 0; i < c; i++){
				now = now * k + (t++);
				if(t >= k) break;
			}
			ans.pb(now);
		}
		for(auto v : ans) cout << " " << v + 1;
		puts("");
	}
}
