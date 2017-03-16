#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double inf=1e9,eps=1e-9;
double c,f,x,ans,tmp,w,t;
int i,j,k,now,tests;
int main(){
	scanf("%d",&tests);
	for (now=1;now<=tests;now++){
		scanf("%lf%lf%lf",&c,&f,&x);
		printf("Case #%d: ",now);
		for (ans=inf,w=2,t=0;;){
			tmp=t+x/w;
			if (ans+eps<tmp) break;
			ans=min(ans,tmp);
			t+=c/w;w+=f;
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}
