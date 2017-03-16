//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "string.h"
#include "stdio.h"

#define N 100005
#define M 40
using namespace std;
double p[N];
double c[N];
int main() {
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	c[0]=1;
	for (int i = 0; i < T; ++i) {
		int A,B;
		scanf("%d%d",&A,&B);
		for (int j = 0; j < A; ++j) {
			scanf("%lf",&p[j]);
			c[j+1]=c[j]*p[j];
		}
		double result=10000005;
		if((B-A+1)*c[A]+(2*B-A+2)*(1-c[A])<result){
			result=(B-A+1)*c[A]+(2*B-A+2)*(1-c[A]);
		}
		if((B+2)<result){
			result=B+2;
		}
		for(int k=1;k<=A;k++){
			if((B-A+1+2*k)*c[A-k]+(2*B-A+2+2*k)*(1-c[A-k])<result){
				result=(B-A+1+2*k)*c[A-k]+(2*B-A+2+2*k)*(1-c[A-k]);
			}
		}
		printf("Case #%d: %.6lf\n",i+1,result);

	}
	return 0;
}
