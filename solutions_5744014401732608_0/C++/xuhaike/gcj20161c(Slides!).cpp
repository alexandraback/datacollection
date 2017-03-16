#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int nq,n;
int ga[110][110];
long long m,lim;
long long pw[60];

int main()
{//freopen("Bs.in","r",stdin);
 //freopen("Bs.out","w",stdout);

 int i,j,q;
 long long x;
 
 pw[0]=1;
 for(i=1;i<=60;i++) pw[i]=pw[i-1]*2;
 cin>>nq;
 for(q=1;q<=nq;q++)
 {	cin>>n>>m;
 	lim=pw[n-2];
 	printf("Case #%d:",q);
 	if(m>lim)
 		printf(" IMPOSSIBLE\n");
 	else
	{	printf(" POSSIBLE\n");
		memset(ga,0,sizeof(ga));
		for(i=2;i<n;i++)
			for(j=i+1;j<=n;j++)
				ga[i][j]=1;
		for(i=2;i<=n;i++)
		{	if(i!=n)
				x=pw[n-i-1];
			else
				x=1;	
			if(m>=x)
			{	ga[1][i]=1;
				m-=x;
			}
		}
		for(i=1;i<=n;i++)
		{	for(j=1;j<=n;j++)
				printf("%d",ga[i][j]);
			printf("\n");
		}
	}
 }
 return 0;
}	
