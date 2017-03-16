#include <cstdio>
typedef long long ll;
ll lowbit(ll x){
	return x & (-x);
}
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a % b);
}
int t;
ll x,y,z;
int f(ll x,ll y){
	if (x == y) return 0;
	if (x > (y >> 1)) return 1;
	return 1 + f(x,y >> 1);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
	for (int T = 1;T <= t;T++){
		scanf("%lld/%lld",&x,&y);
		z = gcd(x,y);
		x /= z;
		y /= z;
		printf("Case #%d: ",T);
		if (y != lowbit(y)){
			printf("impossible\n");
			continue;
		}
		printf("%d\n",f(x,y));
	}
}
