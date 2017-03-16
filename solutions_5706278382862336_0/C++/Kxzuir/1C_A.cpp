#define local
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
int gcd(int a, int b){
	return b==0?a:gcd(b,a%b);
}
int p, q;
int main(){
#ifdef local
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n;
	cin>>n;
	for(int kase=1;kase<=n;kase++){
		printf("Case #%d: ",kase);
		scanf("%d/%d",&p, &q);
		int ans=0;
		int x=gcd(p,q);
		q/=x; p/=x;
		int qq=q;
		while(qq%2==0){qq>>=1;}
		if(qq!=1){printf("impossible\n"); continue;}
		while(p<q){q>>=1;ans++;}
		printf("%d\n",ans);
	}
	return 0;
}

		
