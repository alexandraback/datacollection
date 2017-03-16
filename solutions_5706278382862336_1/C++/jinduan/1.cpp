#include<cstdio>
#include<cstring>
#include<fstream>

using namespace std;
long long T, a, b, ans;

long long gcd(long long a, long long b) {
	if(b%a!=0)
		return gcd((b%a), a);
	return a;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%lld", &T);
	for(long long l=1;l<=T;l++){
		printf("Case #%lld: ", l);
		scanf("%lld/%lld", &a,&b);
		ans = 0;
		
		long long cf = gcd(a,b);
		a /= cf;
		b /= cf;
		
		while(b%2 == 0 && a < b) {
			b/=2;
			ans++;
		}
		while(b>1 && (b%2 == 0))
			b/=2;
		if(b>1){
			printf("impossible\n");
			continue;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
