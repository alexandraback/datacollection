#include <stdio.h>

void main(){

	int T;
	double p[100000];
	int A,B;

	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);

	
	scanf("%d",&T);
	for(int n=0;n<T;n++){
		scanf("%d%d",&A,&B);
//		printf("%d,%d\n",A,B);
		for(int i=0;i<A;i++)
		{
			scanf("%lf",&p[i]);
//			printf("%lf",p[i]);
		}

		double result=B+2;
		for(int i=0;i<A;i++){
//			printf("i:%d\n",i);
			double temp=1.0;
			for(int j=0;j<A-i;j++){
				temp*=p[j];	
//				printf("temp:%.6lf\n",temp);
			}
//			printf("at last temp:%.6lf\n",temp);
			double tempRes;
			tempRes=temp*(B-A+1+2*i)+(1-temp)*(B+1+B-A+1+2*i);
//			printf("tempRes:%.6lf\n",tempRes);
			if(tempRes<result)
				result=tempRes;

		}
		
		printf("Case #%d: %.6lf\n",n+1,result);
	}

//	scanf("%d",&A);
}