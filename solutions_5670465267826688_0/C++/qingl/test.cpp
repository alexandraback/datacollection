#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const int MOD = 1000000007;
const int N = 10005;
char s[N],str[N];
int pre[N],lst[N],h[200],pf[N],lf[N];
int mx[][4]={
0,1,2,3,
1,0,3,2,
2,3,0,1,
3,2,1,0
};
int fg[][4]={
1,1,1,1,
1,-1,1,-1,
1,-1,-1,1,
1,1,-1,-1
};
int got(int a,int b)
{
	return mx[a][b];
}
int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	h['i']=1;
	h['j']=2;
	h['k']=3;
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",ca++);
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",str);
		s[0]=0;
		for(int i=0;i<m;i++)strcat(s,str);
		//puts(s);
		pre[0]=h[s[0]];
		pf[0]=1;
		for(int i=1;i<n*m;i++)
		{
			pre[i]=got(pre[i-1],h[s[i]]);
			pf[i]=pf[i-1]*fg[pre[i-1]][h[s[i]]];
		}
		lst[n*m-1]=h[s[n*m-1]];
		lf[n*m-1]=1;
		for(int i=n*m-2;i>=0;i--)
		{
			lst[i]=got(h[s[i]],lst[i+1]);
			lf[i]=lf[i+1]*fg[h[s[i]]][lst[i+1]];
		}
/*
		for(int i=0;i<n*m;i++)
		{
			if(pre[i]==0)putchar('1');
			else if(pre[i]==1)putchar('i');
			else if(pre[i]==2)putchar('j');
			else if(pre[i]==3)putchar('k');
		}
		puts("");
		for(int i=0;i<n*m;i++)
		{
			if(pf[i]>0)putchar('+');
			else putchar('-');
		}
		puts("");
		puts("------");
		for(int i=0;i<n*m;i++)
		{
			if(lst[i]==0)putchar('1');
			else if(lst[i]==1)putchar('i');
			else if(lst[i]==2)putchar('j');
			else if(lst[i]==3)putchar('k');
		}
		puts("");
		for(int i=0;i<n*m;i++)
		{
			if(lf[i]>0)putchar('+');
			else putchar('-');
		}
		puts("");

*/

		int sf=0,zf=0,flag=0;
		for(int i=0;i<n*m-1;i++)
		{
			if(pre[i]==3&&lst[i+1]==3&&lf[i+1]==1)
			{
				if((zf&&pf[i]==1))
				{
					flag=1;
				}
			}
			if(pre[i]==1&&pf[i]==1)zf=1;
			if(pre[i]==1&&pf[i]==-1)sf=1;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}
