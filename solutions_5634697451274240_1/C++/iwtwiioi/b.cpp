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
char s[1111];
int main() {
	for(int _t=1, T=ri(); _t<=T; ++_t) {
		scanf("%s", s);
		int n=strlen(s), ans=0;
		for(;;) {
			if(s[0]=='-') {
				int i=0;
				for(; i<n-1 && s[i+1]=='-'; ++i);
				for(int j=0; j<=i; ++j) {
					s[j]='+';
				}
				++ans;
			}
			else {
				int i=0;
				for(; i<n-1 && s[i+1]=='+'; ++i);
				if(i==n-1) {
					break;
				}
				for(int j=0; j<=i; ++j) {
					s[j]='-';
				}
				++ans;
			}
		}
		printf("Case #%d: %d\n", _t, ans);
	}
	return 0;
}
