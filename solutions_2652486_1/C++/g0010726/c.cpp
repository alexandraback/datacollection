#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//		#define out stdout
//		#define in stdin

int main(void)
{
#ifndef in
	FILE *in;
	in=fopen("C-small-2-attempt1.in","rt");
	if(in==NULL){
		printf("\a");
		return -1;
	}
#endif
#ifndef out
	FILE *out;
	out=fopen("c.txt","wt");
	if(out==NULL){
		printf("\a");
		return -1;
	}
#endif
	int R=8000,N=12,M=8,K=12,i;
	fscanf(in,"%d %d %d %d %d",&i,&i,&i,&i,&i);
	int num[9],t,j,nt;
	fprintf(out,"Case #1:\n");
	while(R--){
		for(i=1;i<=8;++i)
			num[i]=0;
		for(i=0;i<K;++i){
			fscanf(in,"%d",&t);
			for(j=2;j<=8 && t!=1;++j){
				nt=0;
				while(t!=1 && !(t%j)){
					t/=j;
					++nt;
				}
				if(nt>num[j])
					num[j]=nt;
			}
		}
		int te=(num[2]/2)<(num[3]/2)?(num[2]/2):(num[3]/2);
		num[2]-=te;
		num[3]-=te;
		num[6]+=te;
		while(num[2]>3){
			if(rand()%2){
				num[2]-=2;
				++num[4];
			}
			else{
				num[2]-=3;
				++num[8];
			}
		}
			
		j=N;
		for(i=2;i<=8 && j;++i){
			while(num[i]&&j){
				--num[i];
				--j;
				fprintf(out,"%d",i);
			}
		}
		while(j){
			--j;
			fprintf(out,"%d",rand()%7+2);
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
