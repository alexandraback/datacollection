#include <stdio.h>
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,t,a,b,k,l,r,x,tx,j;
	int s[20];
	int exist[10],pe;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d%d",&a,&b);
		r=0;
		for(x=a;x<=b;x++)
		{
			tx=x;
			i=10;
			while(tx)
			{
				s[i]=tx%10;
				i--;
				tx/=10;
			}
			for(j=i+1;j<=10;j++)
				s[j-i+10]=s[j];
			pe=0;
			for(j=i+2;j<=10;j++)
			{
				if(s[j]==0)continue;
				tx=0;
				for(l=0;l<10-i;l++)
				{
					tx*=10;
					tx+=s[j+l];
				}
				int loi,loy=0;
				for(loi=0;loi<pe;loi++)
					if(exist[loi]==tx)
					{
						loy=1;
						break;
					}
				if(loy)continue;
				if(tx>x&&tx<=b)
				{
					r++;
					exist[pe++]=tx;
					//printf("%d %d\n",x,tx);
				}
			}
		}
		printf("Case #%d: %d\n",k,r);
	}
	return 0;
}