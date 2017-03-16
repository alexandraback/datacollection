#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
int T, c[30], ans[1024], alen;
char s[2016];
int main(){
	freopen("A_in.txt", "r", stdin);
	freopen("A_out.txt", "w", stdout);
	scanf("%d", &T);
	for(int C = 1; C<=T; ++C){
		memset(c, 0, sizeof(c));
		memset(ans, 0, sizeof(ans));
		alen = 0;
		scanf("%s", s);
		int len = strlen(s);
		for(int i = 0; i<len; ++i)
			c[s[i]-'A']++;
		for(int i = 0; i<c['Z'-'A']; ++i){
			c['E'-'A']--;
			c['R'-'A']--;
			c['O'-'A']--;
			ans[alen++] = 0;
		}
		for(int i = 0; i<c['W'-'A']; ++i){
			c['T'-'A']--;
			c['O'-'A']--;
			ans[alen++] = 2;
		}
		for(int i = 0; i<c['U'-'A']; ++i){
			c['F'-'A']--;
			c['O'-'A']--;
			c['R'-'A']--;
			ans[alen++] = 4;
		}
		for(int i = 0; i<c['X'-'A']; ++i){
			c['S'-'A']--;
			c['I'-'A']--;
			ans[alen++] = 6;
		}
		for(int i = 0; i<c['G'-'A']; ++i){
			c['E'-'A']--;
			c['I'-'A']--;
			c['H'-'A']--;
			c['T'-'A']--;
			ans[alen++] = 8;
		}
		for(int i = 0; i<c['O'-'A']; ++i){
			c['N'-'A']--;
			c['E'-'A']--;
			ans[alen++] = 1;
		}
		for(int i = 0; i<c['T'-'A']; ++i){
			c['H'-'A']--;
			c['R'-'A']--;
			c['E'-'A']--;
			c['E'-'A']--;
			ans[alen++] = 3;
		}
		for(int i = 0; i<c['F'-'A']; ++i){
			c['I'-'A']--;
			c['V'-'A']--;
			c['E'-'A']--;
			ans[alen++] = 5;
		}
		for(int i = 0; i<c['S'-'A']; ++i){
			c['E'-'A']--;
			c['V'-'A']--;
			c['E'-'A']--;
			c['N'-'A']--;
			ans[alen++] = 7;
		}
		for(int i = 0; i<c['I'-'A']; ++i){
			c['N'-'A']--;
			c['N'-'A']--;
			c['E'-'A']--;
			ans[alen++] = 9;
		}
		sort(ans, ans+alen);
		printf("Case #%d: ", C);
		for(int i = 0; i<alen; ++i)
			printf("%d", ans[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
