#include<bits/stdc++.h>
using namespace std;
long long expo(long long a, long long b){
  long long result = 1;

  while (b){
    if (b&1){
      result *= a;
    }
    b >>=1 ;
    a *= a;
  }

  return result;
}

int main()
{
	long long t,n,m,b,i,j,k,count,temp,use,imp,ans;
	scanf("%lld",&t);
	for(j=1;j<=t;j++)
	{
		printf("Case #%lld: ",j);
		int array[51][51];
		for(i=1;i<=50;i++)
			for(k=1;k<=50;k++)
				array[i][k]=0;
		scanf("%lld%lld",&b,&m);
		ans=expo(2,b-2);
		if(ans<m)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		if(ans==m)
		{
			printf("POSSIBLE\n");
			for(i=1;i<=b;i++)
			{
				for(k=i+1;k<=b;k++)
				{
					array[i][k]=1;
				}
			}
			for(i=1;i<=b;i++)
			{
				for(k=1;k<=b;k++)
				{
					printf("%d",array[i][k]);
				}
				printf("\n");
			}
			continue;
		}
		
		if(m==1)
		{
			printf("POSSIBLE\n");
			for(i=1;i<=b;i++)
			{
				for(k=1;k<=b;k++)
				{
					if(i==1 && k==b)
						printf("1");
					else printf("0");
				}
				printf("\n");
			}
			continue;
		}
		temp=m;
		count=0;
		printf("POSSIBLE\n");
		while(temp!=1)
		{
			temp=temp/2;
			count++;
		}
		use=count+2;
		array[use][b]=1;
		for(i=1;i<=use-1;i++)
		{
			for(k=i+1;k<=use;k++)
				array[i][k]=1;
		}
		imp=2;
		while((m/2)!=0)
		{
			if(m%2==1)
				array[imp][b]=1;
			imp++;
			m=m/2;
		}
		for(i=1;i<=b;i++)
			{
				for(k=1;k<=b;k++)
				{
					printf("%d",array[i][k]);
				}
				printf("\n");
			}
		
	}

	return 0;
}
