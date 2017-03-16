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
	for(int _t=1, T=ri(); _t<=T; ++_t) {
		printf("Case #%d: ", _t);
		int K=ri(), C=ri(), S=ri();
		if(K==S) {
			for(int i=1; i<=K; ++i) {
				printf("%d%c", i, " \n"[i==K]);
			}
		}
		else {
			if(K>2) {
				if(S<K-2) {
					puts("IMPOSSIBLE");
				}
				else {
					for(int i=2; i<K-1; ++i) {
						printf("%d ", i);
					}
					long long tot=1;
					for(int i=1; i<=C; ++i) {
						tot=tot*K;
					}
					printf("%lld\n", tot-1);
				}
			}
			else {
				puts("IMPOSSIBLE");
			}
		}
	}
	return 0;
}
