#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int p[111][111],test,n;
long long m;
int main()
{
	
	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("22.out","w",stdout);
	cin>>test;
	for (int kk=1;kk<=test;kk++)
	{
		memset(p,0,sizeof(p));
		printf("Case #%d: ",kk);
		cin>>n>>m;
		if (m>(1ll<<(n-2))) {printf("IMPOSSIBLE\n"); continue;}
		else 
		{
			printf("POSSIBLE\n");
			for (int i=1;i<n-1;i++)
			for (int j=i+1;j<n;j++)
			p[i][j]=1;
			for (int i=n-1;i>1;i--)
			if (m>=(1ll<<(i-2))) m-=1ll<<(i-2),p[i][n]=1;
			if (m) p[1][n]=1;
		}
		for (int i=1;i<=n;i++,cout<<endl)
		for (int j=1;j<=n;j++)
		{
			printf("%d",p[i][j]);
		}
	}
	return 0;
}
