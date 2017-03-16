#include <stdio.h>
#include <string.h>

//»±…Ÿq z
char ss[31]=" abcdefghijklmnopqrstuvwxyz";
char ch[31]=" yhesocvxduiglbkrztnwjpfmaq";
int casen;
char inStr[111];
char outStr[111];

int main()
{
	scanf("%d",&casen);
	gets(inStr);
	for(int i=0;i<casen;i++)
	{
		gets(inStr);
		//printf("%s\n",inStr);
		int len = strlen(inStr);
		for(int j=0;j<=len;j++)
		{
			int k = inStr[j]-'a'+1;
			if(k>=1 && k<=26)
			{
				outStr[j]=ch[k];
			}
			else
			{
				outStr[j]=inStr[j];
			}
		}
		printf("Case #%d: %s\n",i+1,outStr);
	}
	
	return 0;
}
