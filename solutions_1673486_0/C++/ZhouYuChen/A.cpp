#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a,n;
double p[102400];
double gao(){
	scanf("%d%d",&a,&n);
	for(int i=0;i<a;++i)scanf("%lf",p+i);
	double ans = n+2,	cr=1.0;
	for(int i=0;i<=a;++i){
		ans = min(ans,a-i+n-i+1+(1-cr)*(n+1));
		cr *= p[i];
	}
	return ans;
}
int main(){
	int Tc,ti;
	for(scanf("%d",&Tc),ti=1;ti<=Tc;++ti)
		printf("Case #%d: %.6lf\n",ti,gao());
	return 0;
}
