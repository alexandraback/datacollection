#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//		#define out stdout
//		#define in stdin
	
int main(void)
{
#ifndef in
	FILE *in;
	in=fopen("A-small-attempt0.in","rt");
	if(in==NULL){
		printf("\a");
		return -1;
	}
#endif
#ifndef out
	FILE *out;
	out=fopen("a.txt","wt");
	if(out==NULL){
		printf("\a");
		return -1;
	}
#endif
	int t,T,r,a,n,i;
	fscanf(in,"%d",&T);
	for(t=1;t<=T;++t){
		fscanf(in,"%d %d",&r,&a);
		n=0;
		for(i=1;a>=0;i+=4){
			++n;
			a-=(2*r+i);
		}
		--n;
		fprintf(out,"Case #%d: %d\n",t,n);
	}

#ifndef in
	fclose(in);
#endif
#ifndef out
	fclose(out);
#endif
	return 0;
}
