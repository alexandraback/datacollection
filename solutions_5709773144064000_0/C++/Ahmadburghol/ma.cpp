#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <memory.h>
#include <algorithm>
using namespace std;
const int N=4;
const double EPS = 1e-6;
int t;
double time,c,f,x,toMul;
double binary_search(double value,double cc){
	double l = 0;
	double r = value;
	toMul = cc;
	for(int i=0;i<128;++i){
		double tm = ((l+r)/2);
		double res = tm*toMul; 
		if(res>=value){
			r = tm;
		}else{
			l = tm;
		}
	}
	return l;
}
double calc(double iHave){
	if(iHave >= x)
		return 0;
	double tm1 = binary_search(c,iHave);
	double tm2 = binary_search(x,iHave);
	return min(calc(iHave+f)+tm1,calc(x)+tm2);
}

int main(){
 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		scanf("%lf %lf %lf",&c,&f,&x);
		double cost = 0;
		double iHave=2;
		while(true){
			double tm1 = binary_search(c,iHave);
			double tm2 = binary_search(x,iHave);
			if(tm2 < tm1+(x/(iHave+f))){
				cost += tm2;
				break;
			}
			else{
				cost += tm1;
			}
			iHave+=f;
		}
		printf("Case #%d: %.7lf\n",k,cost);
	}

	return 0;
} 