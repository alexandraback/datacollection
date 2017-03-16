#define local
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<iostream>
#define lint long long
#define realint int
using namespace std;
lint gcd(lint a, lint b){
	return b==0?a:gcd(b,a%b);
}
lint p, q;
int main(){
#ifdef local
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	cin>>n;
	for(int kase=1;kase<=n;kase++){
		printf("Case #%d: ",kase);
		scanf("%lld/%lld",&p, &q);
		lint ans=0;
		lint x=gcd(p,q);
		q/=x; p/=x;
		lint qq=q;
		while(qq%2==0){qq>>=1;}
		if(qq!=1){printf("impossible\n"); continue;}
		while(p<q){q>>=1;ans++;}
		printf("%lld\n",ans);
	}
	return 0;
}

		
