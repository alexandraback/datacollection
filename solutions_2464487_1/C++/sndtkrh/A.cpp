#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
//(2n-1)までの奇数の平方の和
ll kisu_n2(ll n){
	return n * (4 * n * n - 1) / 3;
}
//(2n)までの偶数の平方の和
ll gusu_n2(ll n){
	return 2 * n * (n + 1) * (2 * n + 1) / 3;
}
//Nのリングを作るのに必要なペンキの量
ll ringN(ll N, ll r){
	return 2 * r * N + kisu_n2(N) - gusu_n2(N-1);
}
ll wa(ll n){
	return n * (n + 1) / 2;
}
ll ringN2(ll N, ll r){
	return 2 * r * N + wa(2 * N - 1);
}

int main(){
	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		ll r, t, ans;
		scanf("%lld %lld", &r, &t);
		ll h = 10000000000;
		ll l = 1;
		for(int i = 0; i < 100; i++){
			ll m = (l + h) / 2;
			if(t >= ringN2(m, r)){
				l = m;
			}else{
				h = m;
			}
		}
		ans = l;
		printf("Case #%d: %lld\n", cnt, ans);
	}
	return 0;
}

