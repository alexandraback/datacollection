#include<stdio.h>

#define S(x) ((x)*(x))
typedef long long ll;

ll solve(ll r,ll n){
	
	ll a = 2*r+1,sum,ans=1;
	
	ll lo=1,hi= n,mid,ano,add;
	
	while(lo<hi){
		
		mid = (lo+hi)/2;
		
		ans = mid;
		sum = a + 2*mid -2;
		ano = n/mid;
		if(sum==ano) break;
		else if(sum>ano) hi = mid -1;
		else lo = mid + 1;
		
	}
	sum = a + 2*ans -2;
	
	while(sum>n/ans){
		ans--;
		sum = a + 2*ans -2;
	}
	//printf("%lld\n",ans);
	while(sum<n/ans){
		add = a + 2*ans;
		ano = n/(ans+1);
		if(add>ano) break;
		ans++;
		sum=add;
	}
	return ans;
}

int main(){
	int t,k=0;
	ll r,n,add,sum,count;
	
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	
	while(t--){
		scanf("%lld%lld",&r,&n);
		
		add = solve(r,n);
		
		printf("Case #%d: %lld\n",++k,add);
	
	}
	return 0;
}
