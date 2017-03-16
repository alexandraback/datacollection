#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

ll f(ll n, ll k, int p){
	ll P=1ll << p;
	ll ans = (n >> p);
	if ((n & (P-1)) > k)
		ans ++;
	return ans;

}

int raz(ll k){
	int p=0;
	ll K=k;
	while(K){
		K/=2;
		p++;
	}
	return p;
}
int main(){
	//freopen("1.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-out.txt","w",stdout);
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

		//int p = raz(k);
		//int A = raz(a);
		//int B = raz(b);


		//for(int i=k;i<(1<<max(A,B));i++){
		//	ans -= f(a, i, p) * f(b, i, p);
		//	printf("%d %d %lld %lld\n", at, i, f(a, i, p), f(b, i, p));
		//}
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++){
				if((i&j) < k){
					ans++;
				}
			}
		printf("%lld\n", ans);
	}
}