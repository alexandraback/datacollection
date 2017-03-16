#include <stdio.h>


char conv[26]={
	'y','h','e','s','o','c','v','x','d','u','i','g','l','b',
	'k','r','z','t','n','w','j','p','f','m','a','q'
};

int main()
{
	int t,i;
	char s;
	FILE* in;
	FILE* out;
	in=fopen("A-small-attempt1.in","r");
	out=fopen("A-small-attempt1.out","w");
	fscanf(in,"%d%c",&t,&s);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		while(fscanf(in,"%c",&s),s!='\n'){
			if(s==' ')fprintf(out," ");
			else fprintf(out,"%c",conv[s-'a']);
		}
		fprintf(out,"\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}

