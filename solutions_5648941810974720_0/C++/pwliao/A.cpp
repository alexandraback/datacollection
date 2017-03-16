#include <cstdio>
#include <cstring>
#include <cassert>
const char *str[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
const int len[]={4,3,3,5,4,4,3,5,5,4};
int cnt[26];
char s[2005];
int ans[10];
void f(char ch, int x)
{
	int k=ch-'A';
	if(cnt[k]) {
		int t=cnt[k];
		for(int i=0;i<len[x];i++)
			cnt[str[x][i]-'A']-=t;
		ans[x]+=t;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++)
	{
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		scanf("%s",s);
		int l=strlen(s);
		for(int i=0;i<l;i++)
			cnt[s[i]-'A']++;
		f('Z',0);
		f('W',2);
		f('U',4);
		f('X',6);
		f('G',8);
		f('O',1);
		f('T',3);
		f('S',7);
		f('V',5);
		f('I',9);
		for(int i=0;i<26;i++)
			assert(cnt[i]==0);
		printf("Case #%d: ",cases);
		for(int i=0;i<=9;i++)
			for(int j=0;j<ans[i];j++)
				printf("%d",i);
		puts("");
	}
	return 0;
}
