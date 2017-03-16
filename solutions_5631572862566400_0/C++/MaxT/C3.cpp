#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T, n, ans, ansv;
int next[1002];
bool visited[1002], flag=false;
int a[1002];
bool check()
{
	a[0]=a[ans];
	a[ans+1]=a[1];
	for (int i=1;i<=ans;i++)
	if (a[i-1]!=next[a[i]] && a[i+1]!=next[a[i]])
		return false;
	return true;
}
void work(int x)
{
	if (x>=4 && a[1]!=next[a[2]] && a[3]!=next[a[2]])
		return;
	if (x>=5 && a[2]!=next[a[3]] && a[4]!=next[a[3]])
		return;
	if (x>=6 && a[3]!=next[a[4]] && a[5]!=next[a[4]])
		return;
	if (x>=7 && a[4]!=next[a[5]] && a[6]!=next[a[5]])
		return;
	if (x>=8 && a[5]!=next[a[6]] && a[7]!=next[a[6]])
		return;
	if (x>=9 && a[6]!=next[a[7]] && a[8]!=next[a[7]])
		return;
		
	if (x==ans+1)
	{
		if (check())
			flag=true;
		return ;
	}
	for (int i=1;i<=n;i++)
	if (!visited[i])
	{
		visited[i]=true;
		a[x]=i;
		work(x+1);
		visited[i]=false;
	}
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&next[i]);
			
		flag=false;
		for (ans=n;ans>=1;ans--)
		if (flag)
		{
			printf("Case #%d: %d\n",k, ans+1);
			break;
		}
		else
			work(1);
		
		//clear();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

