#include <stdio.h>

char s1[30] ,s2[30];
int a[30] ,b[30];
int aa[30] ,bb[30];
int aaa[30] ,bbb[30];
long long ans ,ansa ,ansb ,temp ,p;
long long tans ,ta ,tb;
int n;	
int haha;
void fi(int ii)
{
	int i;
	int z;
	for (i=1 ; i<=n ; i++)
	{
		aaa[i]=a[i];
		bbb[i]=b[i];
	}
	for (i=ii ; i<=n ; i++)
	{
		if (aaa[i]==-1)
		{
			aaa[i]=0;
		}
		if (bbb[i]==-1)
		{
			bbb[i]=9;
		}		
	}
	ta=0;
	tb=0;
	for (i=1 ; i<=n ; i++)
	{
		ta=ta*10+aaa[i];
		tb=tb*10+bbb[i];		
	}
	tans=ta-tb;
	z=0;
	if (tans<ans)
	{
		z=1;
	}
	else if (tans==ans)
	{
		if (ta<ansa)
		{
			z=1;
		}
		else if (ta==ansa)
		{
			if (tb<ansb)
			{
				z=1;	
			}
		}
	}
	if (z)
	{
		if (haha==1)
		{
			ansa=ta;
			ansb=tb;
			ans=tans;			
		}
		else
		{
			ansb=ta;
			ansa=tb;
			ans=tans;			
		}
	}
}
int main(void)
{
	int tt ,ii;
	int i ,j;
		
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%s %s" ,s1+1 ,s2+1);
		for (i=1 ; s1[i] ; i++)
		{
			if (s1[i]=='?')
			{
				a[i]=-1;
			}
			else
			{
				a[i]=s1[i]-'0';
			}
		}
		n=i-1;
		for (i=1 ; s2[i] ; i++)
		{
			if (s2[i]=='?')
			{
				b[i]=-1;
			}
			else
			{
				b[i]=s2[i]-'0';
			}
		}
		ans=1000000000;
		ans*=ans;
		
		
		haha=1;
		for (i=1 ; i<=n ; i++)
		{
			aa[i]=a[i];
			bb[i]=b[i];
		}
		for (i=1 ; i<=n ; i++)
		{
			if (a[i]==-1&&b[i]==-1)
			{
				a[i]=1;
				b[i]=0;
				fi(i+1);
				a[i]=0;
				b[i]=0;
			}
			else if (a[i]==-1)
			{
				if (b[i]!=9)
				{
					a[i]=b[i]+1;
					fi(i+1);
				}
				a[i]=b[i];
			}
			else if (b[i]==-1)
			{
				if (a[i]!=0)
				{
					b[i]=a[i]-1;
					fi(i+1);
				}
				b[i]=a[i];
			}
			else
			{
				if (a[i]>b[i])
				{
					fi(i+1);
				}
				else if (a[i]<b[i])
				{
					break;
				}
				else
				{
					;
				}
			}
		}	
		if (i==n+1)
		{
			fi(i+1);
		}
		
		haha=2;		
		for (i=1 ; i<=n ; i++)
		{
			a[i]=bb[i];
			b[i]=aa[i];
		}	
		for (i=1 ; i<=n ; i++)
		{
			if (a[i]==-1&&b[i]==-1)
			{
				a[i]=1;
				b[i]=0;
				fi(i+1);
				a[i]=0;
				b[i]=0;
			}
			else if (a[i]==-1)
			{
				if (b[i]!=9)
				{
					a[i]=b[i]+1;
					fi(i+1);
				}
				a[i]=b[i];
			}
			else if (b[i]==-1)
			{
				if (a[i]!=0)
				{
					b[i]=a[i]-1;
					fi(i+1);
				}
				b[i]=a[i];
			}
			else
			{
				if (a[i]>b[i])
				{
					fi(i+1);
				}
				else if (a[i]<b[i])
				{
					break;
				}
				else
				{
					;
				}
			}
		}		
		if (i==n+1)
		{
			fi(i+1);
		}
					
		printf("Case #%d: " ,ii);
		for (p=1 , i=0 ; ansa>=p ; p*=10)
		{
			i++;
		}
		if (ansa==0)
		{
			i=1;	
		}
		for (j=i+1 ; j<=n ; j++)
		{
			printf("0");
		}
		printf("%I64d " ,ansa);
		for (p=1 , i=0 ; ansb>=p ; p*=10)
		{
			i++;
		}
		if (ansb==0)
		{
			i=1;	
		}
		for (j=i+1 ; j<=n ; j++)
		{
			printf("0");
		}
		printf("%I64d\n" ,ansb);		
	}

	return 0;
}
