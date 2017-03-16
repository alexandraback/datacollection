#include <stdio.h>
#include <string.h>
int main()
{
	char map[]="yhesocvxduiglbkrztnwjpfmaq";
	freopen("A-small-attempt2.in","r",stdin);
	int n;
	scanf("%d",&n);
	char buf[256],ch;
	FILE * fo=fopen("A.out","w");
	fgets(buf,256,stdin);
	for(int i=1;i<=n;++i)
	{
		fgets(buf,256,stdin);
		fprintf(fo,"Case #%d: ",i);
		for(int i=0;i<strlen(buf)-1;++i)
		{
			if(buf[i]!=' ')ch=map[buf[i]-'a'];
			else ch=buf[i];
			fprintf(fo,"%c",ch);
		}
		fprintf(fo,"\n");
	}
	return 0;
}
