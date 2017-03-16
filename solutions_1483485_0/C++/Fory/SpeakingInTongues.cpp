#include <stdio.h>

char mapping[]="yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char* argv[])
{
	int T;
	char cadena[200];
	scanf("%d\n",&T);
	for (int t=1;t<=T;t++)
	{
		gets(cadena);
		printf("Case #%d: ",t);
		int i=0;
		while (cadena[i])
		{
			if (cadena[i]==' ')
				printf(" ");
			else
				printf("%c",mapping[cadena[i]-'a']);
			i++;
		}
		printf("\n");
	}
	return 0;
}

