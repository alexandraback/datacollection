#include<stdio.h>

long long gcd(long long a,long long b){
	if(a<b){
		long long p;
		p=a;a=b;b=p;
	}
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

bool check(long long x){
	while(x%2==0)x/=2;
	return x==1;
}

int main(){
	int dn;
	scanf("%d",&dn);
	for(int di=0;di<dn;di++){
		long long p,q;
		scanf("%lld/%lld",&p,&q);
		long long d=gcd(p,q);
		p/=d;q/=d;
		printf("Case #%d: ",di+1);
		if(!check(q))puts("impossible");
		else{
			int ans=0;
			while(p<q){
				ans++;
				q/=2;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}