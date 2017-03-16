#include <stdio.h>
#include <math.h>

main()
{
	int T,A,B;
	int i,j,k,len,n,f,cnt;
	int arr[32],c,m;

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d %d",&A,&B);
		cnt=0;
		for(j=A;j<=B;j++)
		{
			n=j;
			len=1;
			while(n/=10)
			{
				len++;
			}
			f=powl(10,len-1);

			n=j;
			c=0;
			for(k=1;k<len;k++)
			{
				if(n%10==0)
				{
					n=n%10*f+n/10;
				 	continue;
				}else
				{
					n=n%10*f+n/10;
				}
				if(n>j && n>=A && n<=B)
				{
					for(m=0;m<c;m++)
					{
						if(n==arr[m])
						{
							break;
						}
					}
					if(m==c)
					{
						cnt++;
						arr[c++]=n;
					}
				}
			}

		}
		printf("Case #%d: %d\n",i,cnt);
	}
}


