#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
	
typedef long long ll;

int t,n,j,a[50],pri[110000],bz[110000],ans[11];

void check()
{
	fo(i,2,10)
	{
		int flag=0;
		fo(k,1,pri[0])
		{
			int tmp=0;
			fo(x,1,n) 
			{
				tmp=tmp*i+a[x];
				if (tmp>pri[k]) break;
				if (x==n&&pri[k]==tmp) return; 
			}
			tmp=0;
			fo(x,1,n) tmp=(tmp*i+a[x])%pri[k];
			if (!tmp)
			{
				ans[i]=pri[k];
				flag=1;
				break;
			}
		}
		if (!flag) return;
	}
	j--;
	fo(i,1,n) printf("%d",a[i]);
	fo(i,2,10) printf(" %d",ans[i]);
	printf("\n");
}

void dfs(int pos)
{
	if (pos==n+1)
	{
		check();
		return;
	}
	if (pos==1||pos==n)
	{
		a[pos]=1;
		dfs(pos+1);
		return;
	}
	a[pos]=0;
	dfs(pos+1);
	if (!j) return;
	a[pos]=1;
	dfs(pos+1);
	if (!j) return;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&t);
	printf("Case #1:\n");
	scanf("%d%d",&n,&j);
	fo(i,2,1000)
		if (!bz[i])
		{
			pri[++pri[0]]=i;
			fo(j,2,1000/i) bz[i*j]=1;
		}
	dfs(1);
}