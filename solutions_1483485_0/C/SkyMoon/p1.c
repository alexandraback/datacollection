#include <stdio.h>

main()
{
	char *pSrc ="abcdefghijklmnopqrstuvwxyz";
	char *pDest="yhesocvxduiglbkrztnwjpfmaq";

	int T,i,j;
	char aLine[1024];

	scanf("%d\n",&T);
	
	for(i=1;i<=T;i++)
	{
		fgets(aLine,1000,stdin);
		for(j=0;aLine[j]!='\n';j++)
		{
			if(aLine[j]==' ')continue;

			aLine[j]=pDest[aLine[j]-'a'];
		}
		printf("Case #%d: %s",i,aLine);
	}
}
		

