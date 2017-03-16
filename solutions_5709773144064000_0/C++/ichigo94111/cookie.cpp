#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T;
int round=0;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("cookie.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		double rate=2;
		double c,f,x;
		double res=0;
		scanf("%lf%lf%lf",&c,&f,&x);
		while(1){
			double tmp1=x/rate;
			double tmp2=c/rate+x/(rate+f);
			if(tmp1<tmp2){
				res+=tmp1;
				break;
			}
			else{
				res+=c/rate;
				rate+=f;
			}
		}
		printf("Case #%d: %.7lf\n",++round,res);
	}
	return 0;
}