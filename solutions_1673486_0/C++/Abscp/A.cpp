#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double ans;
int A,B;
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;scanf("%d",&T);
	for(int t=1;t<=T;++t){
		scanf("%d%d",&A,&B);
		ans=B+2;double si=1.0,pi;
		for(int i=1;i<=A;++i){
			scanf("%lf",&pi);
			si*=pi;
			ans=min(ans,(1-si)*(B+1)+A+B-2*i+1);
		}
		printf("Case #%d: %.10lf\n",t,ans);
	}
	return 0;
}
