#include <stdio.h>
#include <string.h>

int main()
{
	int t,tcase,len,i;
	char str[110],temp;
	char exc[28]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

	FILE *in,*out;
	in=fopen("A-small-attempt1.in","r");
	out=fopen("output.txt","w");

	fscanf(in,"%d",&tcase);
	fscanf(in,"%c",&temp);
	for(t=0;t<tcase;t++)
	{
		fgets(str,110,in);
		len=strlen(str);
		fprintf(out,"Case #%d: ",t+1);
		for(i=0;i<len-1;i++)
		{
			if(str[i]==' ')
				fprintf(out,"%c",str[i]);
			else
				fprintf(out,"%c",exc[str[i]-'a']);
		}
		fprintf(out,"\n");
	}
	return 0;
}