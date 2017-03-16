#include <cstdio>
long long x,r,t,l;

bool isOK(long long m){
	long long k=r+m*2-1;
	k=k*(k+1);
	//printf("%lld %lld %lld : %lld\n",m,k,l,2*(t+l));
	if(2*(t+l)<k){
		return false;
	}
	return true;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%lld",&x);
	long long test,left,right,middle,mx;
	for(test=1;test<=x;test++){
		scanf("%lld %lld",&r,&t);
		left=mx=0; right=707106781;
		l=(r*(r-1))/2;
		for(;left<=right;){
			middle=(left+right)>>1;
			if(isOK(middle)){
				left=middle+1;
				if(mx<middle){ mx=middle; }
			}else{
				right=middle-1;
			}
		}
		printf("Case #%lld: %lld\n",test,mx);
	}
	return 0;
}
