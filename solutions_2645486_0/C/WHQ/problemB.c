#include <stdio.h>
#include <string.h>
#define MAXN 100
int T,E_1,R,N,max,sum;
int v[MAXN];
int DFS(int a,int E){
	int i,k;
	if(a == N)
		return 0;
	for(i=E;i>=0;i--){
		sum += v[a]*i;
		if(a == N-1 && sum > max)
			max = sum;
		k = E-i+R;
		if(k > E_1)
			k = E_1;
		DFS(a+1,k);
		sum -= v[a]*i;
	}
	return 0;
}
int main(){
	FILE *fp1,*fp2;
	fp1=fopen("B-small.in","r");
	fp2=fopen("B.out","w");
	int i,j;
	fscanf(fp1,"%d",&T);
	for(i=0;i<T;i++){
		fscanf(fp1,"%d %d %d",&E_1,&R,&N);
		memset(v,0,sizeof(v));
		for(j=0;j<N;j++){
			fscanf(fp1,"%d",&v[j]);
		}
		sum = 0;
		max = 0;
		DFS(0,E_1);
		fprintf(fp2,"Case #%d: %d\n",i+1,max);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
