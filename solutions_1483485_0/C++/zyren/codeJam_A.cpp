#include <stdio.h>

char S[101], G[101], map[128],Tag[128];
int main()
{
	int i,j,T,cases;
	freopen("G:\\chromeµÄÏÂÔØÇø\\A-small-attempt4.in", "r", stdin);
	freopen("D:\\A4.out", "w", stdout);
	scanf("%d\n", &T);
	j=0;
	while (T--)
	{
		gets(G);
		gets(S);
		i=0;
		while (G[i]!='\0')
		{
			if(G[i]!=' '&&map[G[i]]==0)
			{
				Tag[S[i]]=1;
				map[G[i]]=S[i];
				j++;
			}
			i++;
		}
	}

	map[113]=122;
	map[122]=113;
	map[32]=32;

	scanf("%d\n", &T);
	cases = 0;
	while (cases<T)
	{
		gets(G);
		cases++;
		i=-1;
		while(G[++i]!='\0')
			S[i]=map[G[i]];
		S[i]='\0';
		printf("Case #%d: %s\n", cases, S);
	}
	return 0;
}