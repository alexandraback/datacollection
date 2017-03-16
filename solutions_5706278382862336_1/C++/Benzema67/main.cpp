#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

bool check(ll a){
	while(a){
		if(a % 2 == 0) a /= 2;
		else break;
	}
	if(a > 1) return 0;
	return 1;
}

int main(){
	int T;
	freopen("A-large.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		ll tmp = gcd(a, b);
		a /= tmp;
		b /= tmp;
		if(check(b) == 0){
			printf("Case #%d: impossible\n", t + 1);
			continue;
		}
		int ans = 0;
		while(a < b){
			a *= 2;
			ans++;
		}
		printf("Case #%d: %d\n", t + 1, ans);
	}
}
