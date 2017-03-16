#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<stack>
#include<string>
#define MAX 200000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int dp[MAX+10];
int num[MAX+10];
int cnt[30];
int ans[12];
int siz;
char str[2010];
int min(int a,int b)
{
	return a>b?b:a;
}
int tn(char s){
	return s-'A';
}
int main(void)
{
	int n,t,cas=0;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		int len=strlen(str);
		siz=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<len;i++){
			cnt[tn(str[i])]++;
		}
		memset(ans,0,sizeof(ans));
		ans[0]=cnt[tn('Z')];
		ans[8]=cnt[tn('G')];
		ans[4]=cnt[tn('U')];
		ans[2]=cnt[tn('W')];
		ans[6]=cnt[tn('X')];
		ans[5]=cnt[tn('F')]-ans[4];
		ans[3]=cnt[tn('H')]-ans[8];
		ans[7]=cnt[tn('S')]-ans[6];
		ans[1]=cnt[tn('O')]-ans[0]-ans[2]-ans[4];
		ans[9]=(cnt[tn('N')]-ans[1]-ans[7])/2;
		printf("Case #%d: ",++cas);
		for(int i=0;i<=9;i++){
			for(int j=1;j<=ans[i];j++){
				printf("%d",i);
			}
		}
		puts("");
	}
	return 0;
}
