#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NBUFFER 128

int main(void) {
	char 
		buffer[NBUFFER],
		abc[]={"yhesocvxduiglbkrztnwjpfmaq"};
	int i,j,T;
	FILE *fin=fopen("A-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d\n",&T);
	//printf("T: %d\n",T);
	for(i=0;i<T;i++) {
		//printf("i: %d\n",i);
		fgets(buffer,NBUFFER,fin);
		//puts(buffer);
		fprintf(fout,"Case #%d: ",i+1);
		for(j=0;buffer[j]!=0;j++)
			fputc(islower(buffer[j])?abc[buffer[j]-'a']:buffer[j],fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
