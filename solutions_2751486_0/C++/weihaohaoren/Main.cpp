#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0);
char s[1000010];
bool isok(int p,int q,int n)
{
	int cnt=0;
	for(int i=p;i<=q;i++)
	{
		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
			cnt++;
		else cnt=0;
		if(cnt>=n) return true;
	}
	return false;
}
void work(int n)
{
	int ans=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
		{
			if(isok(i,j,n)) ans++;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		int n;
		scanf("%s",s);
		scanf("%d",&n);
		printf("Case #%d: ",tc);
		work(n);
	}
	fclose(stdout);
	return 0;
}
