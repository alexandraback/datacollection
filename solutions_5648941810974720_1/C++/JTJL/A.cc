#include<bits/stdc++.h>

using namespace std;

string u[10] = {"ZREO", "ONE", "WTO", "THREE", "UFOR", "FIVE", "XSI", "SEVEN", "GEIHT", "INNE"};

int cnt[10000], ans[10000];
char s[10000];

int main(){
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	int T;
	cin>>T;
	for(int o = 1; o <= T; o++){
		scanf("%s", s);
		printf("Case #%d: ", o);
		for(int i = 'A'; i <= 'Z'; i++)
			cnt[i] = 0;
		int l = strlen(s);
		for(int i = 0; i < l; i++){
			cnt[s[i]]++;
		}
		for(int i = 0; i < 10; i++)
			ans[i] = 0;
		for(int i = 0; i <= 8; i += 2){
			ans[i] = cnt[u[i][0]];
			for(int j = 1; j < u[i].length(); j++)
				cnt[u[i][j]] -= cnt[u[i][0]];
			cnt[u[i][0]] = 0;
		}
		for(int i = 1; i <= 9; i += 2){
			ans[i] = cnt[u[i][0]];
			for(int j = 1; j < u[i].length(); j++)
				cnt[u[i][j]] -= cnt[u[i][0]];
			cnt[u[i][0]] = 0;
		}
		for(int i = 0; i <= 9; i++)
			for(int j = 0; j < ans[i]; j++)
				printf("%d", i);
		puts("");
	}
	return 0;
} 
