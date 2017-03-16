#include<stdlib.h>
#include<stdio.h>
using namespace std;

long long factor(long long p,long long q){
	if(p==0)return q;
	if(q==0)return p;
	if(p==1||q==1)return 1;
	if(p>=q)return factor(p%q,q);
	if(q>p)return factor(p,q%p);
}

int main(){
	long long time;
	scanf("%lld",&time);
	for(long long t=1;t<=time;t++){
		long long P,Q;
		scanf("%lld/%lld",&P,&Q);
		long long f = factor(P,Q);
		P = P/f; Q = Q/f;
		bool flag = true;
		long long qq = Q;
		long long ii=0;
		while(qq){
			if(qq==1)break;
			else if((qq%2&&qq>1)||ii>=40){
				flag = false; break;
			}
			ii++;
			qq/=2;
		}
		printf("Case #%lld: ",t);
		if(!flag)
			printf("impossible\n");
		else{
			long long x=1;
			while(1){
				if(P>=(Q/2))break;
				x++;
				Q/=2;
			}
			printf("%lld\n",x);
		}
	}
}
