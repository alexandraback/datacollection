#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	char rep[27]="yhesocvxduiglbkrztnwjpfmaq";
	char g[102];
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	fgetc(stdin);
	for(int i=0;i<t;i++)
	{		
		fgets(g,sizeof(g),stdin);
		int l=strlen(g);
		if(g[l-1]=='\n')
			g[l-1]=0;
		for(int j=0;g[j]!=0;j++)
		{
			if(g[j]!=' ')
				g[j]=rep[g[j]-'a'];
		}
		printf("Case #%d: %s\n",i+1,g);
	}
	return 0;
}