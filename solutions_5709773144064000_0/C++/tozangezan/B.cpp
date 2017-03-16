#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		double ret=c/2;
		double now=0;
		for(int i=0;i<110000;i++){
			ret=min(ret,now+c/(b*i+2));
			now+=a/(b*i+2);
		}
		printf("Case #%d: %.12f\n",t+1,ret);
	}
}