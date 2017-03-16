#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
char number[][20]={"ZERO","ONE","TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int time[100];
int ans[100];
char s[2000+10];
void solve(int x,int t)
{
	ans[x]+=t;
	int len=strlen(number[x]);
	for(int i=0;i<len;i++)time[number[x][i]-'A']-=t;
}
int main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		memset(time,0,sizeof(time));
		memset(ans,0,sizeof(ans));
		scanf("%s",&s);
		int len=strlen(s);
		for(int i=0;i<len;i++)time[s[i]-'A']++;
		solve(0,time['Z'-'A']);
		solve(2,time['W'-'A']);
		solve(4,time['U'-'A']);
		solve(6,time['X'-'A']);
		solve(8,time['G'-'A']);
		solve(1,time['O'-'A']);
		solve(3,time['R'-'A']);
		solve(5,time['F'-'A']);
		solve(7,time['S'-'A']);
		solve(9,time['I'-'A']);
		printf("Case #%d: ",cas);
		for(int i=0;i<=9;i++)for(int j=0;j<ans[i];j++)printf("%d",i);
		printf("\n");
	}
	return 0;
}
