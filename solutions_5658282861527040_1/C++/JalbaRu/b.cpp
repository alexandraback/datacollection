#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

//ll f(ll n, ll k, int p){
//	ll P=1ll << p;
//	ll ans = (n >> p);
//	if ((n & (P-1)) > k)
//		ans ++;
//	return ans;
//
//}

//int raz(ll k){
//	int p=0;
//	ll K=k;
//	while(K){
//		K/=2;
//		p++;
//	}
//	return p;
//}

int razp(ll k){
	int p=0;
	ll K=k;
	while(K){
		K/=2;
		p++;
	}
	//if((1<<p) == k)
		return p;
	//else
	//	return p-1;
}

//ll pr(int a, int b,int k){
//	ll cn=0;
//	for(int i=0;i<a;i++)
//		for(int j=0;j<b;j++)
//			if((i&j) <k)
//				cn++;
//	return cn;
//}

ll w(ll a, ll b, ll k){
	//ll et=pr(a,b,k);
	if(k <= 0 || a<=0 || b<=0)
		return 0;
	if(a<=k && b <= k){
		return a*b;
		//printf("%d %d %d %lld %lld\n", a,b,k, a*b, et);
	}
	if(a==1 && b==1){
		return 1;
	}
	if(a > b) 
		swap(a,b);
	ll A = razp(a);
	ll B = razp(b);
	ll M = max(A, B)-1;
	ll m =(1ll<<M);
	
	if(a==m && b==m){
		m /= 2;
		ll ans=w(m,m,k)*3 + w(m,m,k-m);
		//printf("%d %d %d %lld %lld\n", a,b,k, ans, et);
		return ans;
	}

	
	ll ans = 0;
	if(a<=m && b<=m)
		m/=2;

	if(a<m)
		if(b<m){
			ans += w(a, b, k);
		}
		else{
			ans += w(a, m, k) * (b/m);
			ans += w(a, b%m, k);
		}
	else{
		if(b<m){
			ans += w(m, b, k);
			ans += w(a%m, b, k);
		}
		else{
			ans += w(m, m, k) * (b/m);
			ans += w(a%m, m, k);
			ans += w(m, b%m, k);
			ans += w(a-m, b-m, k-m);
		}

	}
	
	//printf("%d %d %d %lld %lld\n", a,b,k, ans, et);
	return ans;
	

}
int main(){
	//freopen("1.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-out1.txt","w",stdout);
	//freopen("B-large.in","r",stdin);
	//freopen("B-large-out.txt","w",stdout);
	int T;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		ll a,b,k;
		cin >> a >> b >> k;
		ll ans =0;
		//ans=a*b;



		ans = w(a, b, k);
		printf("%lld\n", ans);
	}
}