#include<stdio.h>

int main()
{
	int t,x;
	int p,q,ctr,temp,ans;
	FILE *fp;
	fp=fopen("ans1","w+");
	scanf("%d",&t);
		
	for(x=1;x<=t;x++)
	{
		scanf("%d/%d",&p,&q);
		temp=q;
		for(ctr=0;(temp&1) !=1;ctr++)
			temp>>=1;
		if(p%temp==0)
		{
			p/=temp;q/=temp;
			for(ans=0;p<q;ans++)
			q>>=1;
			fprintf(fp,"Case #%d: %d\n",x,ans);
		}	
		else
			fprintf(fp,"Case #%d: impossible\n",x);	
	}
	return 0;
}
