#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,tmp,g,w;
int i,ans,tests,cc;
ll gcd(ll a,ll b){
	ll r;
	do{
		r=a%b;a=b;b=r;
	}while (r);
	return a;
}
int main(){
	scanf("%d",&tests);cc=0;
	while (tests--){
		cc++;
		scanf("%lld/%lld",&a,&b);
		g=gcd(a,b);
		a/=g;b/=g;
		for (ans=-1,i=1;i<=40;i++){
			tmp=(ll)1<<i;
			if (tmp%b==0){
				w=tmp/b*a;
				for (ans=i,w/=2;w;w/=2,ans--);
				break;
			}
		}
		printf("Case #%d: ",cc);
		if (ans==-1) puts("impossible");else printf("%d\n",ans);
	}
	return 0;
}
