#include <cstdio>

using namespace std;

int main() {
	
	int test; 
	scanf("%d", &test);
	
	for(int k = 1; k <= test; k++) {
		printf("Case #%d: ", k);
		
		int x,y,n;
		scanf("%d %d %d", &n, &x, &y);
		if(x < 0) x = -x;
		
		double p = 0.0;
		
		int j = 1;
		while((j*(j+1))/2 <= n) j+=2;
		j-=2;
		
		if(x+y < j) {
			printf("1.0\n");
			continue;
		}
		
		if(x+y > j+2) {
			printf("0.0\n");
			continue;
		}
		
		n -= (j*(j+1))/2;
		
		int q = y+1;
		
		if(n-j-1 >= q) {
			printf("1.0\n");
			continue;
		}
		
		if(q > n) {
			printf("0.0\n");
			continue;
		}
		
		if(x == 0) {
			printf("0.0\n");
			continue;
		}
		
		double l = 1.0;
		double r = 1.0;
		for(int i = 0; i < n; i++) r/=2.0;
		int ch = 1;
		
		for(int i = 0; i < q; i++) {
			p += ch*r*l;
			r*= 2.0;
			l/= 2.0;
			ch *= n-i;
			ch /= i+1;
		}
		
		p = 1.0 - p;
		
		printf("%.9lf\n", p);
	}
	
	//double g = 1e-8;
	//printf("%lf %.9lf\n", g, g);
	
	return 0;
}
