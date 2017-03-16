#include<stdio.h>

int main()
{
	int t,i,r,c,w,score,f;
	FILE *fp,*fp1;
	if((fp = fopen("A-large.in","r")) == NULL) {
		printf("Cannot open the file\n");
		return 0;
	}
	fp1 = fopen("A-large-output.in","w");
	fscanf(fp,"%d",&t);
	for(i = 1;i <= t;i++) {
		score = 1;
		fscanf(fp,"%d %d %d",&r,&c,&w);
		if(w == 1) {
			score = r*c;
		} else if(w == c) {
			score = w + r - 1;
		} else {
			f = c/w;
			/*if(f == 0) f = c/w;
			else f = c/w + 1;*/
			score = r*f + w;
			f = c%w;
			if(f == 0) score--;
		}
		fprintf(fp1,"Case #%d: %d\n",i,score);
	}
	fclose(fp);
	return 0;
}
