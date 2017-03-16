#include <cstdio>
#include <cstdlib>

/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv

our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up

abcdefghijklmnopqrstuvwxyz
yhesocvxduiglbkrztnwjpfmaq
*/

int main()
{
	static const char conv[]="yhesocvxduiglbkrztnwjpfmaq";
	FILE* fin=fopen("A-small-attempt0.in","r");
	FILE* fout=fopen("A-small-attempt0.out","w");
	char buffer[200];
	int count;
	fgets(buffer,_countof(buffer),fin);
	sscanf(buffer,"%d",&count);
	for(int i=0;i<count;++i)
	{
		fprintf(fout,"Case #%d: ",i+1);
		fgets(buffer,_countof(buffer),fin);
		for(char* p=buffer;*p;++p)
		{
			if('a'<=*p && *p<='z') putc(conv[*p-'a'],fout); else putc(*p,fout);
		}
	}
	fclose(fin);
	fclose(fout);
}