#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<functional>
#include<bitset>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1.0);
const int mod=1000000007;
char c[11],key[11],tar[11];
int k,l,s,cnt,num[1<<20];
void f()
{
	//printf("%s\n",c);
	int i,j,ans=0;
	for(i=0;i+l<=s;i++)
	{
		bool f=true;
		for(j=i;j<i+l;j++)
			if(c[j]!=tar[j-i])
				f=false;
		ans+=f;
	}
	//printf("a%d\n",ans);
	num[cnt++]=ans;
}
void solve(int x)
{
	if(x==s)
	{
		c[s]=0;
		f();
		return;
	}
	int i;
	for(i=0;i<k;i++)
	{
		c[x]=key[i];
		solve(x+1);
	}
}
int main()
{
    freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("Boutput.txt","w",stdout);
	int i,j,t,tt=0,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s%s",key,tar);
		cnt=0;
		memset(num,0,sizeof(num));
		solve(0);
		int mx=0;
		long long ans=0;
		for(i=0;i<cnt;i++)
		{
			ans+=num[i];
			mx=max(mx,num[i]);
		}
		//printf("%d\n",cnt);
		double res=0;
		if(cnt)
			res=mx-(double)ans/cnt;
		printf("Case #%d: %lf\n",++tt,res);
	}
    fclose(stdin);
    fclose(stdout);
	return 0;
}
/*
99
7 6 6
BANANAS
MONKEY
2 3 4
AA
AAA
2 1 2
AB
B
6 2 2
GOOGLE
GO
26 11 100
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ROSENCRANTZ

Case #1: 0.0
Case #2: 0.0
Case #3: 1.0
Case #4: 0.8888889
Case #5: 9.0
*/

