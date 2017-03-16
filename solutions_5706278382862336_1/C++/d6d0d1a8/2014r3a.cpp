#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

long long gcd(long long a,long long b){
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++){
		long long m,n;
		scanf("%lld/%lld",&m,&n);
		long long p=gcd(m,n);
		m/=p;n/=p;
		//printf("%lld %lld %lld\n",m,n,p);
		long long c=n;
		while(c%2==0)c/=2;
		if(c!=1)printf("Case #%d: impossible\n",tt+1);
		else{
		c=n;
		int r=0;
		while(m<c){
			r++;
			c/=2;
		}
		printf("Case #%d: %d\n",tt+1,r);
		}
	}
	return 0;
}