#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
bool test(ll a){
	int cnt = 0;
	while(a > 1){
		if(a % 2) return false;
		a /= 2;
		cnt++;
	}
	return cnt <= 40;
}

int main(){
	//freopen("A-large.in", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		printf("Case #%d: ", cnt);
		ll p, q;
		scanf("%I64d/%I64d", &p, &q);
		ll x = gcd(p, q);
		p /= x, q /= x;
		if(!test(q)){
			puts("impossible");
			continue;
		}
		int ans = 0;
		while(p < q){
			q /= 2;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
