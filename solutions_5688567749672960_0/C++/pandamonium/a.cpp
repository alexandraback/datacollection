#include <cstdio>
using namespace std;
int t;
long long n,ans,pow10[16];
long long rev(long long k){
	long long s=0ll;
	while(k){
		s=s*10ll+k%10ll;
		k/=10ll;
	}
	return s;
}
int main(){
	pow10[0]=1ll;
	for(int x=1;x<=16;x++) pow10[x]=pow10[x-1]*10ll;
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%d",&n);
		if(n<=10ll){
			printf("Case #%d: %lld\n",c,n);
			continue;
		}
		ans=0ll;
		for(int x=1;;x++){
			if(pow10[x]>n){
				if(n<pow10[x-1]+pow10[(x+1)/2]) ans+=n%pow10[(x+1)/2];
				else if(n==pow10[x-1]+pow10[(x+1)/2]) ans+=pow10[(x+1)/2];
				else if(n%pow10[x/2]==0ll) ans+=rev((n-1ll)/pow10[x/2])+pow10[x/2];
				else ans+=rev(n/pow10[x/2])+n%pow10[x/2];
				break;
			}
			else ans+=pow10[x/2]+pow10[(x+1)/2]-1ll;
		}
		printf("Case #%d: %lld\n",c,ans);
	}
	return 0;
}
