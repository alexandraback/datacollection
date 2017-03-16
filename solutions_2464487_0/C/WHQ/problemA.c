#include <stdio.h>
#include <string.h>
int T,r,t;
int main(){
	FILE *fp1,*fp2;
	fp1=fopen("A-small.in","r");
	fp2=fopen("A.out","w");
	int i,ans,sum;
	fscanf(fp1,"%d",&T);
	for(i=0;i<T;i++){
		ans = -1;
		sum = 0;
		fscanf(fp1,"%d %d",&r,&t);
		while(sum <= t){
			ans++;
			sum += 4*ans+1+2*r;
		}
		fprintf(fp2,"Case #%d: %d\n",i+1,ans);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
