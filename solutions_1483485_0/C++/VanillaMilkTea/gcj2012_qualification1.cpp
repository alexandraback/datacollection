#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc,char **argv){
	FILE *fin,*fout;
	char buf1[1024]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvqz";
	char buf2[1024]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upzq";
	char buf[1024];
	int perm[256],cases=0,i=0,j=0;

	for(i=0;i<127;i++)
		perm[buf1[i]]=buf2[i];

	fin=fopen("A-small-attempt0.in","rt");
	fout=fopen("A-small-attempt0.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	
	for(i=0;i<cases;i++){
		fgets(buf,1024,fin);
		fprintf(fout,"Case #%d: ",i+1);
		j=0;
		while(buf[j]==' ' || (buf[j]>='a' && buf[j]<='z')){
			fprintf(fout,"%c",perm[buf[j]]);
			j++;
		}
		fprintf(fout,"\n");
	}

	fclose(fin);
	fclose(fout);
	return 0;
}