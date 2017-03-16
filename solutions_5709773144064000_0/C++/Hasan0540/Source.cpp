#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
double C,F,X;
double calc(double T){
	double t=0,r=2,x=0;
	while(t+(C-x)/r<=T && x+(T-t)*r<X){
		t+=(C-x)/r;
		x+=(C-x);
		x-=C;
		r+=F;
	}
	x+=(T-t)*r;
	return x;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	double l,m,r;
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		printf("Case #%d: ",k);
		scanf("%lf%lf%lf",&C,&F,&X);
		l=0;
		r=X/2;
		for(int i=0;i<128;++i){
			m=(l+r)/2;
			if(calc(m)>=X)
				r=m;
			else
				l=m;
		}
		printf("%.7lf\n",l);
	}
	return 0;
}