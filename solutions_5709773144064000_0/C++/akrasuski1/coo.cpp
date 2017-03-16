/*
 * coo.cpp
 *
 *  Created on: 12 kwi 2014
 *      Author: admin
 */
#include <cstdio>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		double c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double time=0.0;
		double speed=2.0;
		while(1){
			time+=c/speed;
			if((x-c)/speed<x/(speed+f)){
				time+=(x-c)/speed;
				break;
			}
			speed+=f;
		}
		printf("Case #%d: %.7f\n",i+1,time);
	}

}



