#include <stdio.h>
#include <string.h>

const char* mapping = "yhesocvxduiglbkrztnwjpfmaq";

int main(void)
{
	freopen("a.in","rt",stdin);
	freopen("a.out","wt",stdout);
	int T = 0;
	int TK = 0;
	scanf("%d\n",&T);
	while(T--)
	{
		char text[111] = {0};
		gets(text);
		int len = strlen(text);
		for(int i = 0;i < len;i++)
		{
			if(text[i] >= 'a' && text[i] <= 'z')
			{
				text[i] = mapping[text[i]-'a'];
			}
		}
		printf("Case #%d: ",++TK);
		puts(text);
	}
	return 0;
}
