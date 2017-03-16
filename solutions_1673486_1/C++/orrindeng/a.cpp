#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>
double p[100005],pp[100005],qq[100005];
int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.out","w",stdout);
	int n,i,mina;
	int t,a,b,k=0;
	double ans,tp;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		k++;
		for(i=1;i<=a;i++){
			scanf("%lf",&p[i]);
		}
		ans = 100000000;
		pp[1] = 1-p[1];
		qq[1] = p[1];
		for(i=2;i<=a;i++){
			pp[i] = pp[i-1]+qq[i-1]*(1-p[i]);
			qq[i] = qq[i-1]*p[i];
		}
		for(i=0;i<a;i++){
			tp = qq[a-i]*(b-a+2*i+1) + pp[a-i]*(b+1-a+b+1+2*i);
			if(tp<ans) ans=tp;
		}
		if(ans>b+2) ans = b+2;
		printf("Case #%d: %.6lf\n",k,ans);
	}
	return 0;
}