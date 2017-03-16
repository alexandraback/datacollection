#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define MaxA 110000
using namespace std;
int T,A,B,j;
double p[MaxA],ans;
void cmin(double &a,double b){
	if (a>b) a=b;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		scanf("%d%d",&A,&B);
		double P=1;
		ans=B+2;
		for (j=1;j<=A;j++){
			scanf("%lf",&p[j]);
			P*=p[j];
			cmin(ans,P*(A-j+B-j+1)+(1-P)*(A-j+B-j+1+B+1));
		}
		printf("Case #%d: %.6lf\n",i,ans);
	}
	return 0;
}
