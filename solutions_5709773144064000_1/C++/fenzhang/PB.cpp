#include<stdio.h>
#include<algorithm>
#include<math.h>
typedef double dou;
void sol(int uuu){
	dou C,F,X;
	scanf("%lf %lf %lf",&C,&F,&X);
	dou ans=1<<30,tmp=0,tv=2;
	for(int k=0;;k++){
		dou tans=tmp+X/tv;
		if(ans<=tans){
			break;
		}
		ans=tans;
		tmp+=C/tv;
		tv+=F;
	}
	printf("Case #%d: %.7f\n",uuu,ans);
}
int main(){
	freopen("B-large.in","r",stdin);
	freopen("Bout_l.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		sol(ti);
	}
	return 0;
}
