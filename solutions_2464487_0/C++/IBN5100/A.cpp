#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	double a,b,c;
	int T;
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("data1.out","w",stdout);
	scanf("%d",&T);
	int ca=1;
	while(T--){
		double r,t;
		scanf("%lf%lf",&r,&t);
		a=2;
		b=(2*r-1);
		c=-t;
		double ans=(sqrt(b*b-4*a*c)-b)/4;
		printf("Case #%d: %.0lf\n",ca++,floor(ans));
	}
}
