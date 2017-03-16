#include<stdio.h>
#include<math.h>
int main()
{
	int t,cases,a,b,i,ans,j,k,l,p;
	int hold[10],hctr;
	int distinct[20],dctr;
	scanf("%d",&t);
	for(cases=1;cases<=t;cases++)
	{
		ans=0;
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++)
		{
			j=i;
			hctr=0;
			dctr=0;
			while(j>0)
			{
				hold[hctr++]=j%10;
				j=j/10;
			}
			for(k=0;k<hctr-1;k++)
			{
				j=0;
				for(l=k;l>=0;l--)
					j=10*j+hold[l];
				for(l=hctr-1;l>k;l--)
					j=10*j+hold[l];
				if(j>i && j<=b)
				{
					for(p=0;p<dctr;p++)
						if(distinct[p]==j)
							break;
					if(p==dctr)
						distinct[dctr++]=j;
				}
			}
			ans+=dctr;
		}
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}	
				
	
			
