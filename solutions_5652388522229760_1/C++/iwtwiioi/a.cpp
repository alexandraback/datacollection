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
int main() {
	for(int T=ri(), _t=1; _t<=T; ++_t) {
		int n=ri();
		printf("Case #%d: ", _t);
		if(n==0) {
			puts("INSOMNIA");
		}
		else {
			bool vis[10];
			memset(vis, 0, sizeof vis);
			for(int i=1; ; ++i) {
				int x=n*i, flag=0;
				for(; x; vis[x%10]=1, x/=10);
				for(int j=0; j<10; ++j) {
					if(!vis[j]) {
						flag=1;
						break;
					}
				}
				if(!flag) {
					printf("%d\n", n*i);
					break;
				}
			}
		}
	}
	return 0;
}
