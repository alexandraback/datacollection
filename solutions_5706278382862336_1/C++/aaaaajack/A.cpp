#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int main(){
	int t,c,i;
	long long p,q,d;
	bool flag;
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		scanf("%lld/%lld",&p,&q);
		d=gcd(p,q);
		p/=d;
		q/=d;
		flag=false;
		for(i=0;i<=40;i++){
			if(q==1LL<<i) flag=true;
		}
		if(flag){
			for(i=1;i<=40;i++){
				if((q>>i)<=p) break;
			}
		}
		if(flag) printf("Case #%d: %d\n",c,i);
		else printf("Case #%d: impossible\n",c);
	}
	return 0;
}