#include <stdio.h>
#include <string.h>

int main(void)
{
	int t,i,cnt=0,j;
	char s[101];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		cnt=0;
		scanf("%s",s);
		for(j=0;j<strlen(s)-1;j++)
		{
			if(s[j]!=s[j+1])
				cnt++;
		}
		if(s[strlen(s)-1]=='-')
			cnt++;


		printf("Case #%d: %d\n",i+1,cnt);
	}
	
	return 0;
}