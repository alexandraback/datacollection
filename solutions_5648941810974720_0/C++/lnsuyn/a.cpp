#include <stdio.h>

char s[3010];
int a[30];
int ans[30];
int main(void)
{
	int tt ,ii;
	int i ,j ,jj;
	int aa;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		for (i=0 ; i<26 ; i++)
		{
			a[i]=0;
		}
		scanf("%s" ,s);
		for (i=0 ; s[i] ; i++)
		{
			a[s[i]-'A']++;
		}
		for (i=0 ; i<=9 ; i++)
		{
			ans[i]=0;	
		}
		if (a['Z'-'A'])
		{
			aa=a['Z'-'A'];
			ans[0]+=aa;
			a['Z'-'A']-=aa;
			a['E'-'A']-=aa;
			a['R'-'A']-=aa;
			a['O'-'A']-=aa;									
		}
		if (a['W'-'A'])
		{
			aa=a['W'-'A'];
			ans[2]+=aa;
			a['T'-'A']-=aa;
			a['W'-'A']-=aa;
			a['O'-'A']-=aa;									
		}		
		if (a['X'-'A'])
		{
			aa=a['X'-'A'];
			ans[6]+=aa;
			a['S'-'A']-=aa;
			a['I'-'A']-=aa;
			a['X'-'A']-=aa;									
		}	
		if (a['G'-'A'])
		{
			aa=a['G'-'A'];
			ans[8]+=aa;
			a['E'-'A']-=aa;			
			a['I'-'A']-=aa;			
			a['G'-'A']-=aa;
			a['H'-'A']-=aa;
			a['T'-'A']-=aa;									
		}			
		if (a['S'-'A'])
		{
			aa=a['S'-'A'];
			ans[7]+=aa;
			a['S'-'A']-=aa;			
			a['E'-'A']-=aa;			
			a['V'-'A']-=aa;
			a['E'-'A']-=aa;
			a['N'-'A']-=aa;									
		}			
		if (a['U'-'A'])
		{
			aa=a['U'-'A'];
			ans[4]+=aa;
			a['F'-'A']-=aa;
			a['O'-'A']-=aa;
			a['U'-'A']-=aa;
			a['R'-'A']-=aa;									
		}
		if (a['O'-'A'])
		{
			aa=a['O'-'A'];
			ans[1]+=aa;
			a['O'-'A']-=aa;
			a['N'-'A']-=aa;
			a['E'-'A']-=aa;									
		}			
		if (a['R'-'A'])
		{
			aa=a['R'-'A'];
			ans[3]+=aa;
			a['T'-'A']-=aa;			
			a['H'-'A']-=aa;			
			a['R'-'A']-=aa;
			a['E'-'A']-=aa;
			a['E'-'A']-=aa;									
		}		
		if (a['F'-'A'])
		{
			aa=a['F'-'A'];
			ans[5]+=aa;
			a['F'-'A']-=aa;
			a['I'-'A']-=aa;
			a['V'-'A']-=aa;
			a['E'-'A']-=aa;									
		}		
		if (a['E'-'A'])
		{
			aa=a['E'-'A'];
			ans[9]+=aa;
			a['N'-'A']-=aa;
			a['I'-'A']-=aa;
			a['N'-'A']-=aa;
			a['E'-'A']-=aa;									
		}				
						
		printf("Case #%d: " ,ii);
		for (i=0 ; i<=9 ; i++)
		{
			jj=ans[i];
			for (j=1 ; j<=jj ; j++)
			{
				printf("%d" ,i);
			}
		}
		printf("\n");
	}
	
	return 0;
}
