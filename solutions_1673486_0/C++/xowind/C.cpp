#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
double p[100012];
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	int T,tt;
	int A,B;
	int i;
	scanf("%d",&T);
	for(tt=1;tt<=T;++tt){
		double res=1e120;
		double tmp=1.0;
		double ts;
		scanf("%d%d",&A,&B);
		for(i=0;i<A;i++) scanf("%lf",p+i);
		for(i=0;i<=A;i++){
			ts=tmp*(B+A-i-i+1.0)+(1.0-tmp)*(B+B+A-i-i+2.0);
			res=min(res,ts);
			//printf("%.6lf ",ts);
			tmp*=p[i];
		}
		ts=2.0+B;
		//printf("%.6lf ",ts);
		res=min(res,ts);
		//printf("\n");
		printf("Case #%d: %.6lf\n",tt,res);
	}
	return 0;
}