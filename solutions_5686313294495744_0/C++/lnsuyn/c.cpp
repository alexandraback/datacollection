#include <stdio.h>
#include <string.h>

char s1[30] ,s2[30];
char cs1[1010][30] ,cs2[1010][30];
int a[1010] ,b[1010];
int ha[1010] ,hb[1010];
int min(int aa ,int bb)
{
	if (aa<bb)	
	{
		return aa;
	}
	return bb;
}
int main(void)
{
	int tt ,iii;
	int n ,i ,j ,ii ,ti;
	int k1 ,k2;
	int z;
	int ans ,tans;
	
	scanf("%d" ,&tt);
	for (iii=1 ; iii<=tt ; iii++)
	{
		k1=0;
		k2=0;
		scanf("%d" ,&n);
		for (i=1 ; i<=n ; i++)
		{
			scanf("%s %s" ,s1 ,s2);
			z=0;
			for (j=1 ; j<=k1 ; j++)
			{
				if (strcmp(s1,cs1[j])==0)
				{
					z=j;
					break;
				}
			}
			if (!z)
			{
				z=++k1;
				strcpy(cs1[k1],s1);
			}
			a[i]=z;
			z=0;
			for (j=1 ; j<=k2 ; j++)
			{
				if (strcmp(s2,cs2[j])==0)
				{
					z=j;
					break;
				}
			}
			if (!z)
			{
				z=++k2;
				strcpy(cs2[k2],s2);
			}
			b[i]=z;
		}
		ans=n;
		ii=1<<n;
		for (i=3 ; i<ii ; i++)
		{
			for (j=1 ; j<=k1 ; j++)
			{
				ha[j]=1;
			}
			for (j=1 ; j<=k2 ; j++)
			{
				hb[j]=1;	
			}			
			ti=i;
			j=1;
			tans=0;
			while (ti)
			{
				if (ti&1)
				{
					tans++;
					ha[a[j]]=0;
					hb[b[j]]=0;					
				}
				ti>>=1;
				j++;
			}
			z=1;
			for (j=1 ; j<=k1 ; j++)
			{
				if (ha[j]==1)
				{
					z=0;	
				}
			}
			for (j=1 ; j<=k2 ; j++)
			{
				if (hb[j]==1)
				{
					z=0;	
				}	
			}		
			if (z)				
			{
				ans=min(ans,tans);
			}
		}
		ans=n-ans;
		printf("Case #%d: %d\n" ,iii ,ans);
	}
	
	return 0;
}
