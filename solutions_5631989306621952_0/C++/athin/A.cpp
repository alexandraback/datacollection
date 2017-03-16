#include <bits/stdc++.h>

using namespace std;

int n,t,x,i,tes;
char c;
char s[1007];
bool flag[1007];

int main() {
	scanf("%d",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%s",&s);
		printf("Case #%d: ",tes);
		n = strlen(s);
		
		for (i=0 ; i<n ; i++) flag[i] = false;
		x = n-1;
		while (x >= 0) {
			c = 'A';
			for (i=0 ; i<=x ; i++) c = max(c,s[i]);
			for (i=x ; i>=0 ; i--) if (c == s[i]) {
				printf("%c",s[i]);
				flag[i] = true;
				x = i-1;
				i = -1;
			}
		}
		for (i=0 ; i<n ; i++) if (!flag[i]) printf("%c",s[i]);
		printf("\n");
	}
}