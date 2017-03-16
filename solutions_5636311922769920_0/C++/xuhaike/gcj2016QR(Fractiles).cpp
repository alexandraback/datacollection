#include<cstdio>
#include<iostream>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int nq;
int k,c,s;
long long ans;
long long pw[110];

int main()
{//freopen("Ds.out","w",stdout);

 int i,j,q;
 long long x,y;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d%d%d",&k,&c,&s);
 	printf("Case #%d:",q);
 	if(s*c<k)
 		printf(" IMPOSSIBLE\n");
 	else
 	{	pw[0]=1;
 		for(i=1;i<=c;i++) pw[i]=pw[i-1]*k;
 		for(i=1;i<=k;i+=c)
 		{	ans=1;
		 	for(j=c-1;j>=0;j--)
		 		if(i+(c-1-j)<=k)
		 			ans+=pw[j]*(i+(c-1-j)-1);
		 		else
				 	ans+=pw[j]*(k-1);	
 			printf(" %I64d",ans);
		}
		printf("\n");
	}
 }
 return 0;
}
