#include<stdio.h>
main(){
int T,T1;
int A,P;
int i;
double *probab;
double allSuc,min,ans;
scanf("%d",&T);
	for(T1=1;T1<=T;T1++){
		allSuc=1.0;
		min=0.0;
		scanf("%d %d",&A,&P);
		probab=malloc(A*sizeof(double));
		for(i=0;i<A;i++){
			scanf("%lf",&probab[i]);
			allSuc *= probab[i];
			ans = (double)((A-i-1)+(P-i))*allSuc + (double)((A-i-1)+(P-i)+(P+1))*(1-allSuc);
			if(min > ans || min == 0.0)
				min=ans;
//			printf("ans=%lf\n",ans);
		}
		if(min > (double)(P+2) || min == 0.0)
			min=(double)(P+2);
		if(min > (double)(A+P+1)|| min == 0.0)
			min = (double)(A+P+1);
		printf("Case #%d: %lf\n",T1,min);
		free(probab);
	}
}
