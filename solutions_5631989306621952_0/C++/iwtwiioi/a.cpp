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
char _ans[2005], ans[2005], s[2005];
int main() {
	int n=ri();
	for(int t=1; t<=n; ++t) {
		scanf("%s", s);
		printf("Case #%d: ", t);
		int len=strlen(s);
		int first=1, last=0;
		for(int i=0; i<len; ++i) {
			if(first>last || s[i]>=ans[first]) {
				ans[--first]=s[i];
			}
			else {
				ans[++last]=s[i];
			}
		}
		for(int i=first; i<=last; ++i) {
			putchar(ans[i]);
		}
		puts("");
	}
	return 0;
}
