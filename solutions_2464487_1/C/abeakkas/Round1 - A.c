#include <stdio.h>
unsigned long long suqrt(unsigned long long x){
	unsigned long long a=x/2;
	int i;
	for(i=0;i<100;i++){
		a=(a+x/a)/2;
	}
	return a;
}
int main(){
	int T,i,ii;
	unsigned long long n,r,t,a;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%llu %llu",&r,&t);
		n=suqrt(t/2)/2;
		a=n/2;
		while(1){
			if(2*n*n+2*n*r-n>t){
				n-=a;
			}else{
				n+=a;
			}
			a/=2;
			if(a==0)
			a++;
			if(2*n*n+2*n*r-n<=t && 2*n*n+2*n*r+3*n+2*r+1>t) break;
		}
		printf("Case #%d: %llu\n",i+1,n);
	}
	return 0;
}
