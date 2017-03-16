/************************************
Problem: Problem B. Cookie Clicker Alpha
Author: Jorge Ktch
Language: C++
************************************/
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int main(){
	int t;
	int i,cent;
	double c,f,x;
	double ans_coef=2;
	double ans_t1=0;
	double t_acum_anterior=0,t_acum_actual=0;

	scanf("%d",&t);
	for(i=0;i<t;i++){	
		scanf("%lf",&c);
		scanf("%lf",&f);
		scanf("%lf",&x);
		
		t_acum_actual=x/ans_coef;
		ans_t1=c/ans_coef;
		ans_coef=ans_coef+f;

		do{
			t_acum_anterior=t_acum_actual;
			t_acum_actual=ans_t1+x/ans_coef;
			ans_t1=ans_t1+c/ans_coef;
			ans_coef=ans_coef+f;

		}while(t_acum_actual<t_acum_anterior);
		
		printf("Case #%d: %.7lf",i+1,t_acum_anterior);
		if(i!=t-1){
			printf("\n");
		}
		ans_coef=2;
		ans_t1=0;
	}
	return 0;
}
