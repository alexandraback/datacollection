#include<stdio.h>
#include<math.h>
#include<set>

#define maxn 201

using namespace std;

int len = 0, put = 1, n;
double percent[maxn], val[ maxn];

double cauta_bin(double low, double high) {
	double med;
	while( high - low > 0.00000001) {
		med = (high + low)/2;
		double total = 100;
		for( int i = 1; i <= n; ++i) {
			if( percent[i] > med) continue;
			total -= (med - percent[i]);
		}
		if( fabs(total) < 0.00000001) break;
		if( total > 0 ) {
			low = med;
		}
		else high = med;
	}
	return med;
}
int main() {
	
	freopen("safety.in", "r", stdin);
	freopen("safety.out", "w", stdout);
	
	int tt;
	scanf("%d", &tt);
	
	for( int ii = 1; ii <= tt; ++ii) {
		
		double sum = 0;
		scanf("%d", &n);
		for( int i = 1; i <= n; ++i) {
			scanf("%lf", &val[i]);
			sum += val[i];
		}
		for( int i = 1; i <= n; ++i) {
			percent[i] = val[i]/sum*100;
		}
		double med = cauta_bin(0, 200);
		
		printf("Case #%d: ", ii);
		
		for( int i = 1; i < n; ++i) {
			if( percent[i] > med) 
				printf("0 ");
			else printf("%lf ", med - percent[i]);
			
		}
		if( percent[n] > med )
			printf("0\n");
		else printf("%lf\n", med - percent[n]);
		
			
	}
	
	
	
	return 0;
}
