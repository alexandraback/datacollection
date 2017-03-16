#include<stdio.h>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;

int main(){
	int T,a,b;
	double p[100000];
	scanf("%d",&T);
	for(int iT=1;iT<=T;iT++){
		scanf("%d%d%lf",&a,&b,&p[0]);
		for(int ia=1;ia<a;ia++){
			scanf("%lf",&p[ia]);
			p[ia]*=p[ia-1];
		}
		double ans=p[a-1]*(b-a+1)+(1-p[a-1])*(b+b-a+2);
		if(b+2<ans)
			ans=b+2;
		for(int i=1;i+i<a+1;i++){
			double tmp=p[a-1-i]*(i+i+b-a+1)+(1-p[a-1-i])*(i+i+b+b-a+2);
			if(tmp<ans)
				ans=tmp;
		}
		printf("Case #%d: %lf\n",iT,ans);
	}
	return 0;
}
