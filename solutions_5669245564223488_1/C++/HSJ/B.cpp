#include<stdio.h>
#include<string.h>
#define MD 1000000007

int n;
char s[100][120]={0};
int con[26][2]={0},len[100]={0};
int center[26]={0},all[26]={0},cnt=0;
__int64 fac[210]={0},ans;
bool check[26]={0};
bool left_ch(int idx){
	idx = con[idx][0];
	while(idx>=0){
		if(check[idx]) return false;
		check[idx] = true;
		idx = con[idx][0];
	}
	return true;
}
bool right_ch(int idx){
	idx = con[idx][1];
	while(idx>=0){
		if(check[idx]) return false;
		check[idx] = true;
		idx = con[idx][1];
	}
	return true;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	bool ch;
	int i,j;
	int t,t2;
	fac[0] = 1;
	for(i=1;i<=200;i++){
		fac[i] = fac[i-1] * (__int64)i;
		fac[i] %= MD;
	}
	scanf("%d",&t2);
	for(t=1;t<=t2;t++){
		for(i=0;i<26;i++) con[i][0] = con[i][1] = -1, center[i] = all[i] = 0, check[i] = false;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<120;j++) s[i][j] = 0;
		}
		for(i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		ch = false;
		for(i=0;i<n;i++){
			len[i] = strlen(s[i]);
			if(s[i][0] == s[i][len[i]-1]){
				for(j=0;j<len[i];j++){
					if(s[i][j] != s[i][0]) break;
				}
				if(j!=len[i]){
					ch = true;
					break;
				}
				all[s[i][0] - 'a']++;
			}
			else{
				if(con[s[i][0]-'a'][1]>=0 || con[s[i][len[i]-1]-'a'][0]>=0){
					ch = true;
					break;
				}
				con[s[i][0]-'a'][1] = s[i][len[i]-1]-'a';
				con[s[i][len[i]-1]-'a'][0] = s[i][0]-'a';
				for(j=0;j<len[i];j++){
					if(s[i][j] != s[i][0]) break;
				}
				for(j++;j<len[i];j++){
					if(s[i][j] != s[i][j-1]){
						center[s[i][j-1]-'a']++;
					}
				}
			}
		}
		cnt=0;
		for(i=0;i<26;i++){
			if(center[i] && (all[i] || con[i][0]>=0 || con[i][1]>=0 || center[i]>=2)){
				ch = true;
				break;
			}
			if((all[i] || con[i][0]>=0 || con[i][1]>=0) && !check[i]){
				check[i] = true;
				if(!left_ch(i) || !right_ch(i)){
					ch = true;
					break;
				}
				cnt++;
			}
		}
		if(ch){
			printf("Case #%d: 0\n",t);
			continue;
		}
		ans = fac[cnt];
		for(i=0;i<26;i++){
			ans *= fac[all[i]];
			ans %= MD;
		}
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}