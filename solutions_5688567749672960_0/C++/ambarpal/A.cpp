#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll rev( ll n){
	ll res=0;
	while (n > 0){
		res *= 10;
		res += (n%10);
		n /= 10;
	}
	return res;
}
int main()
{
	ll t; scanf("%lld", &t);
	for (ll test = 1; test <= t; test++){
		ll n; scanf("%lld", &n);
		vector <ll> lev(1000010,0), vis(1000010, 0);
		queue <ll> q;
		q.push(1);
		vis[1] = 1;
		while (!q.empty() && !vis[n]){
			ll h = q.front(); q.pop();
			//~ printf("%lld\n", h);
			ll cur1 = rev(h);
			if (!vis[cur1]){
				vis[cur1] = 1;
				q.push(cur1);
				lev[cur1] = lev[h]+1;
			}
			ll cur2 = h + 1;
			if (!vis[cur2]){
				vis[cur2] = 1;
				q.push(cur2);
				lev[cur2] = lev[h]+1;
			}		
		}
		printf("Case #%lld: %lld\n", test, lev[n] + 1);
	}
}
