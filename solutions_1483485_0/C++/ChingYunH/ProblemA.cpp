#include <cstdio>
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	char ch,map[] = "yhesocvxduiglbkrztnwjpfmaq";
	int cn,t;
	scanf("%d",&t);getchar();
	for(cn=1;cn<=t;cn++)
	{
		printf("Case #%d: ",cn);
		while(scanf("%c",&ch)!=EOF && ch!='\n')
		{
			if(ch == ' ') printf(" ");
			else printf("%c",map[ch-'a']);	
		}	
		printf("\n");
	}	
}
