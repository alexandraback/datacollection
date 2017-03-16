#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
#define LL long long
#define For(i,n) for(int (i)=1;(i)<=(n);(i)++)
FILE*f1;
int d[1010],k,l,s;
int tnum,tx,map[1010];
char ss[1010],st[1010],seat[1010];
/*double dp(int a,int b)
{
	if(a>s)return 0;
	double x=0;
	for(int i=0;i<=25;i++)
	{ 
		if(i+'A'==st[b])
		{
			if(b==l)
				x+=(dp(a+1,1)+1)+*map[i]/k;
			else x+=dp(a+1,b+1)*map[i]/k
		}
		else
		{
			x+=dp(a+1,next[b])*map[i]/k;
		}
	} 
	return f[a][b]=x;
}*/

void search(int a)
{
	if(a==s+1)
	{
		tx++;
		for(int i=1;i<=s;i++)
		{
			int j;
			for(j=1;j<=l;j++)
			{
				if(st[j]!=seat[i+j-1])
					break;
				if(j==l)
					tnum++;
			}
		}
		return;
	}
	for(int i=1;i<=k;i++)
	{
		seat[a]=ss[i];
		search(a+1);
	}

}

int findmax()
{
	for(int i=2;i<=l;i++)
		for(int j=1;j<=l;j++)
		{
			if(i+j-1>l)
			{
				return (s-(l-i+1))/(i-1);
			}
			if(st[i+j-1]!=st[j])
				break;

		}
	return s/l;
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T,n,m,w;
	char a;
	scanf("%d",&T);
	For(tcase,T)
	{
		printf("Case #%d: ",tcase);
		scanf("%d%d%d\n",&k,&l,&s);
		memset(map,0,sizeof(map));
		for(int i=1;i<=k;i++)
		{
			scanf("%c",&a);
		//	printf("x%c\n",a);
			ss[i]=a;
			map[a-'A']++;
		}
		scanf("\n");
		for(int i=1;i<=l;i++)
			scanf("%c",&st[i]);
		bool flag=0;
		for(int j=1;j<=l;j++)
		{
			for(int i=1;i<=k;i++)			
			{
				if(st[j]==ss[i])
					break;
				if(i==k)flag=1;
			}
		}
		if(flag==1){printf("0.0\n");continue;} 
		double maxx=findmax();
		//printf("%6lf\n",dp(1,1));
		tx=0,tnum=0;
		search(1);
		double expx=(double)tnum/tx;
		printf("%lf\n",maxx-expx);
	}
    return 0;
} 
