#include <stdio.h>
#include <string.h>

char s[1010];
int main(void)
{
	int tt ,ii;
	int i;
	int ans;
	
	scanf("%d" ,&tt);
	for (ii=1 ; ii<=tt ; ii++)
	{
		scanf("%s" ,s+1);
		ans=0;
		for (i=strlen(s+1) ; i>0 ; i--)
		{
			if (s[i]=='-')
			{
				ans++;
				break;	
			}
		}
		for (i-- ; i>0 ; i--)
		{
			if (s[i]!=s[i+1])
			{
				ans++;	
			}
		}
		printf("Case #%d: %d\n" ,ii ,ans);
	}
	
	return 0;
}
