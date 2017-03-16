#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
#define pb push_back
inline int ri() {
	int x=0, f=1, c=getchar();
	for(; c<48||c>57; f=c=='-'?-1:f, c=getchar());
	for(; c>47&&c<58; x=x*10+c-48, c=getchar());
	return x*f;
}
ll fac[111];
int main() {
	for(int T=ri(), _t=1; _t<=T; ++_t) {
		printf("Case #%d:\n", _t);
		int n=ri(), m=ri(), tot=0;
		ll lim=(1ll<<n)-1;
		for(ll i=(1ll<<(n-1))|1; i<=lim; i+=2) {
			bool flag=1;
			for(int k=2; k<=10; ++k) {
				fac[k]=0;
				for(int j=2; j<min(i, 1000ll); ++j) {
					int pw=1, sum=0;
					for(int t=0; t<n; ++t, pw=pw*k%j) {
						if(i&(1ll<<t)) {
							sum=(sum+pw)%j;
						}
					}
					if(sum==0) {
						fac[k]=j;
						break;
					}
				}
				if(!fac[k]) {
					flag=0;
					break;
				}
			}
			if(flag) {
				for(int j=n-1; j>=0; --j) {
					printf("%d", bool(i&(1ll<<j)));
				}
				for(int k=2; k<=10; ++k) {
					printf(" %lld", fac[k]);
				}
				puts("");
				if(++tot==m) {
					break;
				}
			}
		}
	}
	return 0;
}
