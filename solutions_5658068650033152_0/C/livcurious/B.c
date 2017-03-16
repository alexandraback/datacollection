#include<stdio.h>
int main()
{
	unsigned short t,t1,m,n,k,s,i,j,p,q;//m vertical and n horizontal lines, k intersections to enclose, s are require d stones
	scanf("%hu",&t1);
	for(t=1;t<=t1;t++)
	{
		scanf("%hu%hu%hu",&n,&m,&k);
		if(n<3||m<3||k<5)
		{	
			printf("Case #%hu: %hu",t,k);
			goto end;
		}
		if(m<n)//making m greater
		{
				m=m+n;
				n=m-n;
				m=m-n;
		}
		if((n==4&&m==4)||(n==4&&m==5))
			if(k==10)
			{
				printf("Case #%hu: 7",t,);
				goto end;
			}
		if(n==4&&m==5)
			if(k==13)
			{
				printf("Case #%hu: 9",t,);
				goto end;
			}
		for(i=1;i<n-1;i++)
		{
			for(j=1;j<=i;j++)
			{
				if(((i+2)*(j+2)-4)>k)
				{
					if(j==1)
					{
						i--;
						j=i;
						goto out;
					}
					j--;
					goto out;
				}
			}
		}
		j=n-2;
		for(i=n-1;i<m-1;i++)
		{
				if(((i+2)*(j+2)-4)>k)
				{
						i--;
						goto out;
				}
		
		}
		i--;
		out:;
		s=2*(i+j)+(k-(i+2)*(j+2)+4);
		printf("Case #%hu: %hu\n",t,s);
		end:;
	}
	return 0;
}
