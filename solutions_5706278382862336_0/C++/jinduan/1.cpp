#include<cstdio>
#include<cstring>
#include<fstream>

using namespace std;
int T, a, b, ans;

int gcd(int a, int b) {
	if(b%a!=0)
		return gcd((b%a), a);
	return a;
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	for(int l=1;l<=T;l++){
		printf("Case #%d: ", l);
		scanf("%d/%d", &a,&b);
		ans = 0;
		
		int cf = gcd(a,b);
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
		printf("%d\n", ans);
	}
	return 0;
}
