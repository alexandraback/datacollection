#include <stdio.h>

double a[3010] ,tempa[3010];
int b[3010] ,tempb[3010];
void mergesort(double *a ,int *b ,int n1 ,int n2);
int main(void)
{
	int t ,i;
	int n ,nn ,j;
	int ans1 ,ans2 ,temp ,temp2;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf("%d" ,&n);
		nn=n+n;
		for (j=1 ; j<=nn ; j++)
		{
			scanf("%lf" ,&a[j]);
		}
		for (j=1 ; j<=n ; j++)
		{
			b[j]=1;
		}	
		for (j=j ; j<=nn ; j++)
		{
			b[j]=2;			
		}	
		mergesort(a,b,1,nn);
		ans1=0;
		temp=0;
		for (j=nn ; j ; j--)
		{
			if (b[j]==2)
			{
				temp++;	
			}	
			else
			{
				break;	
			}
		}
		temp2=0;
		if (temp)
		{
			for (j=1 ; j<=nn ; j++)
			{
				if (b[j]==1)
				{
					temp--;
					if (!temp)
					{
						break;	
					}
				}
				else
				{
					temp2++;
				}	
			}
		}
		else
		{
			j=0;			
		}
		for (j++ ; j<=nn ; j++)
		{
			if (b[j]==1)
			{
				if (temp2)
				{
					temp2--;
					ans1++;
				}
			}
			else
			{
				temp2++;
			}
		}
		temp=0;
		ans2=0;
		for (j=nn ; j ; j--)
		{
			if (b[j]==1)
			{
				temp++;
				if (temp>ans2)
				{
					ans2=temp;	
				}
			}
			else
			{
				temp--;
			}	
		}		
		printf("Case #%d: %d %d\n" ,i ,ans1 ,ans2);
	}
	
	return 0;
}

void mergesort(double *a ,int *b ,int n1 ,int n2)
{
	int a1 ,a2 ,n12;
	int i ,j;
		
	if (n1<n2)
	{	
		n12=(n1+n2)/2;
		mergesort(a,b,n1,n12);
		mergesort(a,b,n12+1,n2);
		for (i=n1 ; i<=n2 ; i++)
		{
			tempa[i]=a[i];	
			tempb[i]=b[i];
		}
		a1=n1;
		a2=n12+1;
		for (i=n1 ; (a1<=n12 && a2<=n2) ;i++)
		{
			if (tempa[a1]<tempa[a2])
			{
				a[i]=tempa[a1];
				b[i]=tempb[a1];
				a1++;
			}
			else
			{
				a[i]=tempa[a2];
				b[i]=tempb[a2];
				a2++;				
			}
		}
		if (a1>n12)
		{
			for (j=a2 ; j<=n2 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}
		}
		else
		{
			for (j=a1 ; j<=n12 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}			
		}
	}
}
