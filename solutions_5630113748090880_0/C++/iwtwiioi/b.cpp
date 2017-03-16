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
int a[10005];
int main() {
	for(int T=ri(), _t=1; _t<=T; ++_t) {
		printf("Case #%d:", _t);
		int n=ri();
		memset(a, 0, sizeof a);
		for(int i=1; i<=n*2-1; ++i) {
			for(int j=1; j<=n; ++j) {
				int x=ri();
				a[x]++;
			}
		}
		for(int i=1; i<=2500; ++i) {
			if(a[i]&1) {
				printf(" %d", i);
			}
		}
		puts("");
	}
	return 0;
}
