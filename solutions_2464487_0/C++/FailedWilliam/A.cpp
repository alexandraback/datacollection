#include<stdio.h>
const char inf[]="A-small-attempt0.in";
const char ouf[]="A-small-attempt0.out";

int T;
long long r,t;

long long ans;

void input(){
    scanf("%I64d%I64d",&r,&t);
}

void work(){
    long long L,R,mid;
    L=0;R=1LL<<32;
    while(L<R){
	mid=(L+R+1)>>1;
	if((2*(double)r+2*(double)mid-1)*(double)mid > 3e18)
	    R=mid-1;
	else if((2*r+2*mid-1)*mid <= t)
	    L=mid;
	else
	    R=mid-1;
    }
    ans=L;
}

void output(){
    printf("Case #%ld: %I64d\n",T,ans);
}

int main(){
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    int totT;
    scanf("%ld",&totT);
    for(T=1;T<=totT;T++){
	input();
	work();
	output();
    }
    return 0;
}
