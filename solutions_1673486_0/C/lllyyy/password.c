#include <stdio.h>

double prob[100000];
double res[100002];

int dbcmp(const void *v1,const void* v2){
	double *d1=(double*)v1,*d2=(double*)v2;
	if(*d1>*d2)
		return 1;
	else if(*d1==*d2)
		return 0;
	return -1;
}

int main(){
	double mul,num1,num2;
	int i,j,k,m,n,p,curr,total,numcase;
	FILE *out=fopen("password.out","w");
	scanf("%d",&numcase);
	for(i=0;i<numcase;i++){
		scanf("%d %d",&curr,&total);
		for(j=0;j<curr;j++){
			scanf("%lf",&prob[j]);
		}
		mul=1.0;num1=total+curr-1+total+1;num2=total+1;
		for(k=0;k<curr;k++){
			mul*=prob[k];
			//printf("num1:%lf num2:%lf mul:%lf\n",num1,num2,mul);
			res[k]=num1-num2*mul;
			num1-=2;
		}
		res[curr]=total+2;
		res[curr+1]=curr+total+1;
		qsort(res,curr+2,sizeof(double),dbcmp);
		fprintf(out,"Case #%d: %.6lf\n",i+1,res[0]);
	}
	fclose(out);

	return 0;
}
