#include<stdio.h>
void main(void){
	FILE *fin,*fout;
	int T,A,N;
	int i,j,k,t,min,s;
	int size[101];
	int m[101];
	fin=fopen("A-small-attempt0.in","rw");
	fout=fopen("out.txt","ww");
	fscanf(fin,"%d",&T);
	for(t=1;t<=T;t++){
		fscanf(fin,"%d%d",&A,&N);
		//printf("%d",A);
		min=N;
		for(i=0;i<N;i++){
			fscanf(fin,"%d",&size[N]);
			j=i-1;
			while(j>=0&&size[j]>size[N]){
				size[j+1]=size[j];
				j--;
			}
			size[j+1]=size[N];
		}
		j=0;
		for(i=0;i<N;i++){
			if(A>size[i]){
				A+=size[i];
				min--;
			}else{
				if(A>1){
					m[j++]=min;
					while(A<=size[i]){
						A+=(A-1);
					//	printf("#%d ",A);
						min++;
					}
					A+=size[i];
					min--;
				}
			}
			//printf("*%d ",A);
		}
		for(i=0;i<j;i++){
			if(min>m[i]) min=m[i];
		}
		fprintf(fout,"Case #%d: %d\n",t,min);
	}
	fclose(fin);
	fclose(fout);
}