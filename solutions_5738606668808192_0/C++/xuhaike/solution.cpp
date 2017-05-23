#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int nq,n,m;
int a[40],c[40];
long long pw[20][40],b[40];

int check(int i)
{int j;
 
 for(j=2;j<=50;j++)
 {	if(j>=b[i]) break;
 	if(b[i]%j==0)
	{	c[i]=j;
		return 1;
	}
 }
 return 0;
}
 	
int main()
{//freopen("Cs.out","w",stdout);

 int i,j,q,flag;
 
 for(i=2;i<=10;i++)
 {	pw[i][0]=1;
 	for(j=1;j<=32;j++)
 		pw[i][j]=pw[i][j-1]*i;
 }
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d%d",&n,&m);
 	printf("Case #%d:\n",q);
 	memset(a,0,sizeof(a));
 	memset(b,0,sizeof(b));
 	a[0]=1;
 	a[n-1]=1;
 	for(i=2;i<=10;i++) b[i]=1+pw[i][n-1];
 	while(m>0)
 	{	flag=1;
	 	for(i=2;i<=10;i++) 
 			if(!check(i))
 			{	flag=0;
 				break;
 			}
 		if(flag)
		{	for(i=n-1;i>=0;i--) printf("%d",a[i]);
			for(i=2;i<=10;i++) printf(" %d",c[i]);
			printf("\n");
			m--;
		}
		i=1;
		while(a[i]==1)
		{	for(j=2;j<=10;j++) b[j]-=pw[j][i];
			a[i]=0;
			i++;
		}
		a[i]++;
		for(j=2;j<=10;j++) b[j]+=pw[j][i];
	}
 }
 return 0;
}
