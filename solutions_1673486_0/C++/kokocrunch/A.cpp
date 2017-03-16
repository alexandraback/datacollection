#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define EPS 1e-8
using namespace std;
int TC;
int A,B;
double P[100010];
double E;
double prob;
double err;
int main(){
	int i,j,k;
	scanf("%d",&TC);
	for(int tc=0;tc<TC;tc++){
		
		scanf("%d%d",&A,&B);
		prob=1.0;P[0]=1;
		for(i=1;i<=A;i++){
			scanf("%lf",P+i);
			P[i]*=P[i-1];
		}
		E=1+B+1;
		for(i=0;i<=A;i++){
			E=min(E,P[i]*(A+B-2*i+1)+(1.0-P[i])*(A+B-2*i+1+B+1));
		}
		printf("Case #%d: %.6lf\n",tc+1,E+EPS);
	}
	return 0;
}
			
