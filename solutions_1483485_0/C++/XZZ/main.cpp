#include <stdio.h>
#include <string.h>

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char p[] = "yhesocvxduiglbkrztnwjpfmaq";
	int n;
	int i;
	int Case = 1;
	scanf("%d", &n);
	getchar();
	char input[150];
	while (n--)
	{
		gets(input);
		for (i=0; i<strlen(input); i++)
		{
			if(input[i]>='a' && input[i]<='z') input[i] = p[input[i]-'a'];
		}
		printf("Case #%d: %s\n", Case++, input);
	}
}