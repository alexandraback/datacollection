#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cnt=0;
ll f(ll x) {
	ll sq=sqrt(x);
	if (x==1) return -1;
	for (ll i=2; i<=sq; i++) if (x%i==0) return i;
	return -1;
}
int main () {
	freopen("C-large.out", "w", stdout);
	printf("Case #1:\n");
	for (int i=32769; i<65536; i+=2) {
		vector<ll>v;
		for (int j=2; j<=10; j++) {
			long long num=i, m=1, n=0;
			for (int k=0; k<16; k++) {
				if (i&(1<<k)) n+=m;
				m*=j;
			}
			ll fact=f(n);
			if (fact!=-1) v.push_back(fact);
			else break;
		}
		if (v.size()==9) {
			cnt++;
			for (int j=15; j>=0; j--) {
				if (i&(1<<j)) printf("1");
				else printf("0");
			}
			for (int j=15; j>=0; j--) {
				if (i&(1<<j)) printf("1");
				else printf("0");
			}
			for (int i=0; i<v.size(); i++) printf(" %lld", v[i]);
			printf("\n");
			if (cnt==500) return 0;
		}
	}
}
