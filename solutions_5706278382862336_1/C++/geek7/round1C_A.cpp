#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowbit(x) (x & (-x))
typedef long long LL;

LL gcd(LL a, LL b){
	return b == 0 ? a : gcd(b , a % b);
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, cases = 1;
	scanf("%d", &n);
	LL x, y;
	char op;
	while(n--){
		scanf("%lld%c%lld", &x, &op, &y);
		LL z = gcd(x, y);
		x /= z, y /= z;
		int ans = 0;
		while(x < y){
			x *= 2;
			z = gcd(x, y);
			x /= z, y /= z;
			if(y != lowbit(y)){
			    ans = 1e9;
			    break;
			}
			++ans;
			if(ans > 40) break;
		}
		if(ans > 40)	printf("Case #%d: impossible\n", cases++ );
		else printf("Case #%d: %d\n", cases++, ans);
	//	printf("%lld %lld\n", x, y);
	}
	return 0;
}
