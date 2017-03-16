#include<stdio.h>
#define MAX_KEY_TYPE 200
#define MAX_CHEST 200
#define MAX_KEYS 400
int keys[MAX_KEY_TYPE+1];
int kg[MAX_KEY_TYPE+1];
int chests[MAX_CHEST+1][MAX_KEYS+2];
int opened[MAX_CHEST+1];
int solution[MAX_CHEST+1];
int K,N;
int solve(int n);
void main(void){
	int i,k,t,tcase,imp;
	FILE *fin,*fout;
	fin=fopen("D-small-attempt8.in","rw");
	fout=fopen("out.txt","ww");
	fscanf(fin,"%d\n",&tcase);
	for(t=1;t<=tcase;t++){
	//	printf("%d:",t);
		fscanf(fin,"%d%d",&K,&N);
	//	printf("%d %d\n",K,N);
		for(k=0;k<=MAX_KEY_TYPE;k++) {
			keys[k]=0;
			opened[k]=0;
			kg[k]=0;
		}
		while(K--){
			fscanf(fin,"%d",&k);
		//	printf("%d ",k);
			keys[k]++;
			opened[k]++;
		}
	//	printf("\n");
		for(i=1;i<=N;i++){
			fscanf(fin,"%d%d",&chests[i][0],&chests[i][1]);
			kg[chests[i][0]]++;
			keys[chests[i][0]]--;
			chests[i][2]=0;
			for(k=3;k<chests[i][1]+3;k++){
				fscanf(fin,"%d",&chests[i][k]);
				if(chests[i][k]==chests[i][0]) chests[i][2]++;
				keys[chests[i][k]]++;
			}
		}
		fprintf(fout,"Case #%d:",t);
		imp=0;
		for(i=0;i<=MAX_KEY_TYPE;i++){
			if(keys[i]<0){
				imp=1;
				break;
			}
		}
		if(imp){
			fprintf(fout," IMPOSSIBLE\n");
		}
		else{
			for(i=0;i<=MAX_KEY_TYPE;i++){
				keys[i]=opened[i];
				opened[i]=0;
			//	printf("%d ",keys[i]);
			}
		//	printf("\n");
			if(solve(0)){
				for(k=0;k<N;k++) fprintf(fout," %d",solution[k]);
				fprintf(fout,"\n");
			}else{
				fprintf(fout," IMPOSSIBLE\n");
			}
		}
	//	printf("\n");
	}
	fclose(fin);
	fclose(fout);
}
int solve(int n){
	if(n==N){
		return 1;
	}else{
		int i,j;
		for(i=1;i<=N;i++){
			if(!opened[i]&&(keys[chests[i][0]]>1||
				(keys[chests[i][0]]==1&&(keys[chests[i][0]]==kg[chests[i][0]]||chests[i][2]>0)))){
			//	printf("*%d",i);
				opened[i]=1;
				kg[chests[i][0]]--;
				keys[chests[i][0]]--;
				for(j=3;j<chests[i][1]+3;j++) keys[chests[i][j]]++;
				solution[n]=i;
				if(solve(n+1)) return 1;
				opened[i]=0;
				kg[chests[i][0]]++;
				keys[chests[i][0]]++;
				for(j=3;j<chests[i][1]+3;j++) keys[chests[i][j]]--;
			}
		}
		return 0;
	}
}