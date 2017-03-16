#include <cstdio>

using namespace std;

#define LL long long

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int k = 1; k <= T; k++) {
		printf("Case #%d: ",k);
		LL P,Q;
		char c;
		scanf("%lld%c%lld", &P, &c, &Q);
		
		LL base = 1;
		base = base << 40;
		LL a = 0; LL b = base;
		
		while(a + 1 < b) {
			LL m = (a+b)/2;
			
			if(m*Q <= P*base) {
				a = m;
			}  else {
				b = m;
			}
		}
		
		if(a*Q != P*base) {
			printf("impossible\n");
			continue;
		}
		
		int g = 41;
		LL w = 1;
		while(w <= a) {
			w = w << 1;
			g--;
		}
		
		printf("%d\n", g);
	}
	
	return 0;
}
