#include <stdio.h>
#include <string.h>
#define LEN 100
long long r,t;
int T;
long long get_ans(long long L,long long R){
	if(L>=R)
		return R;
	long long M;
	M = (L+R)/2;
	if(M*(2*M-1+2*r) <= t)
		return get_ans(M+1,R);
	else
		return get_ans(L,M);
}
int main(){
	FILE *fp1,*fp2;
	fp1=fopen("A-large.in","r");
	fp2=fopen("A.out","w");
	int i;
	long long ans;
	fscanf(fp1,"%d",&T);
	for(i=0;i<T;i++){
		fscanf(fp1,"%lld %lld",&r,&t);
		ans = get_ans(1,707106781);
		fprintf(fp2,"Case #%d: %d\n",i+1,ans);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
