#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//		#define out stdout
//		#define in stdin
int C(int a,int b){
	int n=1;
	if(a-b>b)
		b=a-b;
	for(int i=a;i>b;--i)
		n*=i;
	for(int i=a-b;i>1;--i)
		n/=i;
	return n;
}
	
int main(void)
{
#ifndef in
	FILE *in;
	in=fopen("B-small-attempt0.in","rt");
	if(in==NULL){
		printf("\a");
		return -1;
	}
#endif
#ifndef out
	FILE *out;
	out=fopen("b.txt","wt");
	if(out==NULL){
		printf("\a");	
		return -1;
	}
#endif
	int T,N,X,Y;
	int key;
	fscanf(in,"%d",&T);
	for(int t=1;t<=T;++t){
		fscanf(in,"%d %d %d",&N,&X,&Y);
		fprintf(out,"Case #%d: ",t);
		if(X<0)
			X*=-1;
		key=(X+Y)/2;
		int gap=N-(2*key*key+3*key+1-(2*key-Y));
		
		if(gap>=0)
			fprintf(out,"1.0");
		else if(Y==2*key){
			fprintf(out,"0.0");
		}
		else{
			N-=(2*(key-1)*(key-1)+3*key-2);
			if(N<Y+1)
				fprintf(out,"0.0");
			else{
				if(N-(2*key)>=Y+1)
					fprintf(out,"1.0");
				else{
					double sum=0;
					for(int i=Y+1;i<=N;++i){
						sum+=C(N,i);
					}
					while(N--)
						sum/=2;
					fprintf(out,"%f",sum);
				}
			}
		}
		fprintf(out,"\n");
	}
#ifndef in
	fclose(in);
#endif
#ifndef out
	fclose(out);
#endif
	return 0;
}
