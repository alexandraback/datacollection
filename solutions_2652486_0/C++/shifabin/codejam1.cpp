#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int n,m,k;
bool d;
int a[100],b[100];
bool pig()
{
	int i;
	for(i=1;i<=k;i++)
	{
		if (b[i]==1)               continue;
		if (a[1]*a[2]*a[3]==b[i])  continue;
		if (a[1]*a[2]==b[i])       continue;
		if (a[2]*a[3]==b[i])       continue;
		if (a[1]*a[3]==b[i])       continue;
		if (a[1]==b[i])            continue;
		if (a[2]==b[i])            continue;
		if (a[3]==b[i])            continue;
		return false;
	}
	return true;
}
void dfs(int x)
{
	int i;
	if (x==n+1)
	{
		//pig();
		if (n==1)
		{
			a[2]=1;
			a[3]=1;
		}
		if (n==2)
		{
			a[3]=1;
		}
		if (pig())
		{
			d=true;
		}
		return ;
	}
	for(i=2;i<=m;i++)
	{
		a[x+1]=i;
		dfs(x+1);
		if (d==true)  return ;
	}

}
int main()
{
//		freopen("C.in","r",stdin);freopen("C.out","w",stdout);
	freopen("C-small-1-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	

    int i,ii,tt;
	scanf("%d",&tt);
	scanf("%d",&tt);
	printf("Case #1:\n");
	scanf("%d%d%d",&n,&m,&k);
	for(ii=1;ii<=tt;ii++)
	{
		
		for(i=1;i<=k;i++)
			scanf("%d",&b[i]);
		d=false;
		dfs(0);
		for(i=1;i<=n;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	
	
	
	
	
	
	
	return 0;

}