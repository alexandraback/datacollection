#include<bits/stdc++.h>
using namespace std;

int cnt[100];
char s[1000];

int main(){
	freopen("Bs0.in", "r", stdin);
	freopen("Bs0.out", "w", stdout);
	int T, n, m;
	cin>>T;
	for(int o = 1; o <= T; o++){
		printf("Case #%d: ", o);
		scanf("%s", s);
		int l = strlen(s);
		int tot = s[l-1] == '-';
		for(int i = 1; i < l; i++)
			tot += s[i] != s[i-1];
		printf("%d\n", tot);
	}
	return 0;
} 
