#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int cases;
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &cases);
	fo(_case,1,cases+1) {
		printf("Case #%d: ", _case);
		char str[1234];
		char ans[2345];
		fo(i,0,2345) ans[i] = '\0';
		int fr = 1000, bck = 1001;
		scanf("%s", str);
		ans[fr] = str[0];
		int n = strlen(str);
		fo(i,1,n) {
			if (str[i] >= ans[fr]) {
				fr--;
				ans[fr] = str[i];
			}
			else ans[bck++] = str[i];
		}
		printf("%s\n", ans + fr);
	}

	return 0;
}