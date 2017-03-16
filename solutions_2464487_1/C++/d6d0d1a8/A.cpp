#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long area(long long n,long long r){
	long long result;
	//printf("%d\n", (2*n+2*r-1)*n);
	return  (2*n+2*r-1)*n;
}

int main(){
	double pi=asin(1.0)*2;
	int n,t,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long long t,r;
		scanf("%lld%lld",&r,&t);
		//printf("%lld %lld\n",r,t);
		long long low=1;
		long long upper=1;
		while(area(upper,r)<=t){			
			low=upper;
			upper*=2;
		}
		while(upper-low>1){
			long long mid=(upper+low)/2;
			if(area(mid,r)<=t){
				low=mid;
			}else{
				upper=mid;
			}
		}
		printf("Case #%d: %lld\n",i+1,low);
		
	}
	while(1);
	return 0;
}

