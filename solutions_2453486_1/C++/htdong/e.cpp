#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 40
#define MM 10010
char s[NN][NN];
int _,tt;
int h(char c,int r)
{
	int s1=0,s2=0;
	for(int i=0;i<4;i++)
	{
		if(s[r][i]==c) s1++;
		if(s[r][i]=='T') s2++;
	}
	if(s2==1 && s1==3) return 1;
	if(s2==0 && s1==4) return 1;
	return 0;
}
int l(char c,int r)
{
	int s1=0,s2=0;
	for(int i=0;i<4;i++)
	{
		if(s[i][r]==c) s1++;
		if(s[i][r]=='T') s2++;
	}
	if(s2==1 && s1==3) return 1;
	if(s2==0 && s1==4) return 1;
	return 0;
}
int z(char c)
{
	int s1=0,s2=0;
	for(int i=0;i<4;i++)
	{
		if(s[i][i]==c) s1++;
		if(s[i][i]=='T') s2++;
	}
	if(s2==1 && s1==3) return 1;
	if(s2==0 && s1==4) return 1;
	s1=0,s2=0;
	for(int i=0;i<4;i++)
	{
		if(s[i][3-i]==c) s1++;
		if(s[i][3-i]=='T') s2++;
	}
	if(s2==1 && s1==3) return 1;
	if(s2==0 && s1==4) return 1;
	return 0;
}
int main()
{
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	scanf("%d",&_);
	for(tt=1;tt<=_;tt++)
	{
		int flag=0;
		for(int i=0;i<4;i++)
		{
			scanf("%s",s[i]);
			for(int j=0;j<4;j++) if(s[i][j]=='.') flag=1;
		}
		int ans=-1;
		printf("Case #%d: ",tt);
		for(int i=0;i<4;i++)
		{
			if(h('X',i) || l('X',i)) {ans=1;break;}
			if(h('O',i) || l('O',i)) {ans=2;break;}
		}
		if(ans==-1)
		{
			if(z('X')) ans=1;
			else if(z('O')) ans=2;
		}
		if(ans==-1)
		{
			if(flag) puts("Game has not completed");
			else puts("Draw");
		}
		else if(ans==1) puts("X won");
		else puts("O won");
	}
	return 0;
}
