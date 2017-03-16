#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100100
using namespace std;
int a,b;
double p[MAX];
double q[MAX];
int main(){
	int T;
	int ca=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)
			scanf("%lf",&p[i]);
		double all=1;
		double ans;
		q[0]=1;
		for(int i=0;i<a;i++)
			all*=p[i];
		for(int i=0;i<a;i++)
			q[i+1]=q[i]*p[i];
		ans=(b-a+1)*all+(b-a+1+b+1)*(1-all);
		for(int i=1;i<=a;i++){
			double tmp=q[a-i]*(i+b-a+i+1)+(1-q[a-i])*(i+b-a+i+1+b+1);
			if(tmp<ans)
				ans=tmp;
		}
		double tmp=1+b+1;
		if(tmp<ans)
			ans=tmp;
		printf("Case #%d: %lf\n",ca++,ans);
	}
	return 0;
}
