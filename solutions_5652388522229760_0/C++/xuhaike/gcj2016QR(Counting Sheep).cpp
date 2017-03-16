#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int nq,n,ans;

int main()
{//freopen("A.out","w",stdout);
 
 int i,j,k,s,q,x;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d",&n);
 	s=0;
 	ans=0;
 	for(i=1;i<=100000;i++)
 	{	j=n*i;
 		while(j)
 		{	x=j%10;
 			s|=(1<<x);
			j/=10;
		}
		if(s==(1<<10)-1)
		{	ans=n*i;
			break;
		}
	}
	printf("Case #%d: ",q);
	if(s==(1<<10)-1)
		printf("%d\n",ans);
	else
		printf("INSOMNIA\n");
 }
 return 0;
}
