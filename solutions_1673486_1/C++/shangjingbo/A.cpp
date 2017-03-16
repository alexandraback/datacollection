#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn	=	100005;

double p[maxn],pre[maxn];
int a,b;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		scanf("%d%d",&a,&b);
		pre[0]=1;
		for (int i=0;i<a;++i){
			scanf("%lf",&p[i]);
			pre[i+1]=pre[i]*p[i];
		}
		double ans=1+b+1;
		for (int i=0;i<=a;++i){
			double res=a-i;
			res+=pre[i]*(b-i+1)+(1-pre[i])*(b-i+1+b+1);
			ans=min(ans,res);
		}
		printf("Case #%d: %.10f\n",test,ans);
	}
	return 0;
}
