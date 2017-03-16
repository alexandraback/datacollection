#include <bits/stdc++.h>

using namespace std;

int i,t,tes,n,ans;
bool minuss;
char s[1007];

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%s",&s);
		n = strlen(s);
		ans = 0;
		minuss = true;
		for (i=n-1 ; i>=0 ; i--) {
			if (minuss) {
				if (s[i] == '-') {
					ans++;
					minuss = !minuss;
				}
			} else {
				if (s[i] == '+') {
					ans++;
					minuss = !minuss;
				}
			}
		}
		printf("Case #%d: %d\n",tes,ans);
	}
}