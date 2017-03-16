#include<stdio.h>

int main()
{
	int i, t, p, j, s, k, l, m, n, q, r;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		printf("Case #%d: ",i+1);
		scanf("%d %d %d %d",&j,&p, &s, &k);
		if(s<k)
		{
			printf("%d\n",j*p*s);
			for(l=0;l<j;l++)
			{
				for(m=0;m<p;m++)
				{
					for(n=0;n<s;n++)
						printf("%d %d %d\n",l+1,m+1,n+1);
				}
			}
		}
		else if(p<k)
		{
			printf("%d\n",j*p*k);
			for(l=0;l<j;l++)
			{
				for(m=0;m<p;m++)
				{
					for(n=0;n<k;n++)
						printf("%d %d %d\n",l+1,m+1,n+1);
				}
			}
		}
		else
		{
			printf("%d\n",j*p);
			for(q=0;q<k/j;q++)
			{
				for(l=q*0;l<(q+1)*j&&l<j;l++)
				{
					for(m=q*k;m<(q+1)*k && m<p ;m++)
					{
						for(n=q*k;n<(q+1)*k && n<s ;n++)
							printf("%d %d %d\n",l+1,m+1,n+1);
					}
				}
			}
		}
	}
	return 0;
}
