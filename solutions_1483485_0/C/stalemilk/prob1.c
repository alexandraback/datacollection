#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[26] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
	char  c;
	int x,y,z;
	FILE *ifile;
	ifile = fopen("input.txt","r");
	FILE *ofile;
	ofile = fopen("output.txt","w");
	int t;
	int k=1;
	fscanf(ifile,"%i",&t);
	c = getc(ifile);
	while(t--)
	{
		fprintf(ofile,"Case #%i: ", k);
		c = getc(ifile);
		while(c!='\n')
		{
			if(c>='a' && c<='z')
				c = a[c-'a'];
			putc(c,ofile);
			c = getc(ifile);
		}
		putc('\n',ofile);
		k++;
	}
	fclose(ifile);
	fclose(ofile);
}
