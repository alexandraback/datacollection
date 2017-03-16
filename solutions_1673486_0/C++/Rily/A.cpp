#include<stdio.h>
#include<string.h>
#include<stdlib.h>

double calculate(int A, int B,double* p){
	double pip=1.0;
	double s[4];
	for(int i=0;i<A;i++)pip=pip*p[i];
	// s1
	double s1=pip*(B-A+1)+(1-pip)*(B-A+1+B+1);
	// s2
	double s2all[100000];
	for(int j=1;j<=A;j++)s2all[j]=0;
	double correctp=1;
	for(int j=1;j<=A;j++){
		// del A-j+
		s2all[j-1]=correctp*((A-j+1)*2+B-A+1)+(1-correctp)*((A-j+1)*2+B-A+1+B+1);
		correctp=correctp*p[j-1];
	}

	// s3
	double s2=10000000;
	double s3=B+2;
	double s4=B+2;
	for(int k=0;k<A;k++){
		if(s2all[k]<s2){
			s2=s2all[k];
		}
	}

	s[0]=s1;s[1]=s2;s[2]=s3;s[3]=s4;
	double smin=10000000;
	for(int k=0;k<4;k++){
		if(s[k]<smin){
			smin=s[k];
		}
	}

	return smin;
}


void run(){
	int N;
	int A,B;
	double p[50000];
	double result;
	char str[10000];
	scanf("%d\n",&N);

	for(int i=0;i<N;i++){
		scanf("%d %d",&A,&B);
		for(int j=0;j<A;j++)scanf("%lf",&(p[j]));

		result=calculate(A,B,p);
		// result
		printf("Case #%d: ",i+1);
		printf("%.6lf",result);
		printf("\n");
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
