#include <bits/stdc++.h>

using namespace std;

#define pb push_back
int cnt[30];
int T,cas=0;
char s[10000];
map<char,int> M;
string num[10];
int ans[100000],ah;
void init(){
	for(int i=0;i<26;i++){
		M[(char)(i+'A')]=i;
	}
	num[0]="ZERO";
	num[1]="ONE";
	num[2]="TWO";
	num[3]="THREE";
	num[4]="FOUR";
	num[5]="FIVE";
	num[6]="SIX";
	num[7]="SEVEN";
	num[8]="EIGHT";
	num[9]="NINE";
}
bool dfs(int last){
	bool f=1;
	for(int i=0;i<26;i++){
		if(cnt[i]!=0){
			f=0;
			break;
		}
	}
	if(f) return 1;
	for(int i=last;i<10;i++){
		int f=1;
		for(int j=0;j<num[i].size();j++){
			if((--cnt[M[num[i][j]]])<0) f=-1;
		}
		ans[ah++]=i;
		if(f==1&&dfs(i)) return 1;
		ah--;
		for(int j=0;j<num[i].size();j++){
			++cnt[M[num[i][j]]];
		}
	}
}
int main(){
	freopen("./in","r",stdin);
	freopen("./out","w",stdout);
	init();
	cin>>T;
	while(T--){
		printf("Case #%d: ",++cas);
		scanf("%s",s);
		int len=strlen(s);
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<len;i++){
			cnt[s[i]-'A']++;
		}
		ah=0;
		dfs(0);
		for(int i=0;i<ah;i++) printf("%d",ans[i]);
		puts("");
	}
	return 0;
}
