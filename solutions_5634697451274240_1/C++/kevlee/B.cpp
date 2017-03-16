#include <bits/stdc++.h>
using namespace std;
int T, ans, n;
char s[1005];
bool done() {
	for (int i=0; i<n; i++) if (s[i]=='-') return false;
	return true;
}
int main () {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		scanf(" %s", s);
		n=strlen(s);
		ans=0;
		while (true) {
			if (done()) break;
			for (int i=0; i<n; i++) {
				if (s[i]=='-') {
					if (i>0) ans++;
					for (int j=0; j<i; j++) {
						s[j]='-';
					}
					break;
				}
			}
			if (done()) break;
			ans++;
			for (int i=0; i<n; i++) {
				if (s[i]=='+') break;
				s[i]='+';
			}
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}
