#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n,m;
char s[111];
int main(){
	Init;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ){
		printf("Case #%d: ", i);
		scanf("%s", s);
		m = strlen(s);
		s[m ++ ] = '+';
		int t = 0;
		for (int i = 1; i < m; i ++ )
			if (s[i] != s[i - 1]) t ++ ;
		printf("%d\n", t);
	}
}
