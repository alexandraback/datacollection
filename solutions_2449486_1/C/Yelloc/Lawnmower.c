#include<stdio.h>
#define MAX_ARRAY 100
void main(void){
	int t,tcase;
	int N,M;
	int h[MAX_ARRAY][MAX_ARRAY],rMax[MAX_ARRAY],cMax[MAX_ARRAY];
	int i,j;
	int bAns;
	FILE * fin,* fout;
	fin = fopen("B-large.in","rw");
	fout = fopen("out.txt","ww");
	fscanf(fin,"%d",&tcase);
	for(t=1;t<=tcase;t++){
		fscanf(fin,"%d%d",&N,&M);
		for(i=0;i<N;i++){
			for(j=0;j<M;j++)
				fscanf(fin,"%d",&h[i][j]);
		}
		for(i=0;i<N;i++){
			rMax[i] = 0;
			for(j=0;j<M;j++){
				if(i==0) cMax[j]=0;
				if(h[i][j]>rMax[i]) rMax[i]=h[i][j];
				if(h[i][j]>cMax[j]) cMax[j]=h[i][j];
			}
		}
		bAns=1;
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				if(h[i][j]<rMax[i]&&h[i][j]<cMax[j]){
					bAns = 0 ;
					break;
				}
			}
			if(!bAns) break;
		}
		fprintf(fout,"Case #%d: ",t);
		if(bAns) fprintf(fout,"YES\n");
		else fprintf(fout,"NO\n");
	}
	fclose(fin);
	fclose(fout);
}