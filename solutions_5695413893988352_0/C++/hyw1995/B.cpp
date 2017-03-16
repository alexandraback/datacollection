#include<bits/stdc++.h>
using namespace std;
map<char,int> Map;
int ans[15];
char a[100],b[100];
void debug()
{
	
}
int x,y,now;
char ans1[10],ans2[10];
void dfs(char * s,int p,int n,int cmp = -1)
{
	if (p == n)
	{
		int xx = 0;
		for (int i=0;i<n;i++) xx = xx * 10 + s[i] - '0';
		if (cmp == -1) dfs(b,0,strlen(b),xx);
		else
		{
			if (abs(cmp - xx) < now || abs(xx-cmp)==now && cmp<x || abs(xx-cmp)==now && cmp==x && xx<y)
			{
				x = cmp;
				y = xx;
				now = abs(cmp - xx);
				memset(ans1,0,sizeof(ans1));
				memset(ans2,0,sizeof(ans2));
				for (int i=0;i<strlen(a);i++) ans1[i] = a[i];
				for (int i=0;i<strlen(b);i++) ans2[i] = b[i];
			}
		}
		return;
	}
	if (s[p]=='?')
	{
		for (int i=0;i<=9;i++) 
		{
			s[p]='0'+i;
			dfs(s,p+1,n,cmp);
		}
		s[p]='?';
	}
	else dfs(s,p+1,n,cmp);
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,test = 0;
	scanf("%d\n",&T);
	while (T--)
	{
		scanf("%s %s\n",a,b);
		now = 10000;
		dfs(a,0,strlen(a));
		printf("Case #%d: %s %s\n",++test,ans1,ans2);
	}
}
