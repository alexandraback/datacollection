#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAX 1<<20
int a[25],sum[MAX+3];
int main()
{
	int T,t,N,i,j,ans,temp,ok,jj,ii,ans2;
	//freopen("C-small-attempt4.in","r",stdin);
	//freopen("C-small-attempt4.out","w",stdout);
	scanf("%d",&T);
	for(t=1;t<=T;++t)
	{
		memset(sum,0,sizeof(sum));
		ok=0;
		printf("Case #%d:\n",t);
		scanf("%d",&N);
		for(i=0;i<N;++i)
			scanf("%d",&a[i]);
//	i=273;
		for(i=1;i<MAX;++i)
		{
			temp=i;
			j=0;
			while(i)
			{
			ans=i&1;
		//	if(ans)
		//	printf("%d*\n",a[j]);
	
			sum[temp]+=ans*a[j];
			++j;
			i=i>>1;
		//	printf("%d$$\n",i);
			}
		//	printf("%d####\n",sum[273]);
			i=temp;

			for(j=1;j<i;++j)
			{
				if(sum[i]==sum[j])
				{
					ok=1;
				//	printf("%d i=%d j=%d %d %d&&&\n",t,i,j,sum[i],sum[j]);
					goto L;
				}
			}
		}
L:

		if(ok)
		{
			temp=j;
	     	ii=i;
			jj=0;
			while(i)
			{
			ans=i&1;
			ans2=j&1;
		    if(ans && !ans2)
			{
				if(ok)
					ok=0;
				else
					printf(" ");
				printf("%d",a[jj]);
			}
			++jj;
			i=i>>1;
			j=j>>1;
			}
			printf("\n");
			
			jj=0;
			i=temp;
			j=ii;
			while(i)
			{
			ans=i&1;
			ans2=j&1;
		    if(ans && !ans2)
			{
				if(!ok)
					ok=1;
				else
					printf(" ");
				printf("%d",a[jj]);
			}
			++jj;
			i=i>>1;
			j=j>>1;
			}
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;

}