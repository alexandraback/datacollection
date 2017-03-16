#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int ma=0,cnt,k,l,v[30];
int tot=0,now=0;
char s[10],p[10],s1[10];
int Calc()
{
	int ans=0;
	for (int i=0;i+l-1<cnt;i++)
	{
		int j;
		for (j=0;j<l;j++)
			if (p[i+j]!=s[j]) break;
		if (j==l)
			ans++;
	}
	return ans;
}
void dfs(int x)
{
	if (x==cnt)
	{
		int k=Calc();
		ma=max(ma,k);
		now+=k;
		tot++;
		return;
	}
	for (int i=0;i<k;i++)
	{
		p[x]=s1[i];
		dfs(x+1);
	}
}
int main()
{
	freopen("t.in","r",stdin),freopen("t.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d%d",&k,&l,&cnt);
		scanf("%s",s1);
		scanf("%s",s);
		for (int i=0;i<k;i++)
			v[s1[i]-'A'+1]=1;
		int ok=1;
		for (int i=0;i<l;i++)
			if (!v[s[i]-'A'+1])
				ok=0;
		if (!ok)
		{
			printf("0.0\n");
			continue;
		}
		else
		{
			ma=now=tot=0;
			dfs(0);
			printf("%.10f\n",(double)ma-(double)now/tot);
		}
	}
	return 0;
}
