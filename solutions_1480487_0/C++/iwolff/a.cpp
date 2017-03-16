#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 210
#define EPS 1e-6

double vet[MAXN];

int main() {
	int nt,n,nteste=1;
	double S,m;
	scanf("%d",&nt);
	while (nt--) {
		S = 0.0;
		scanf("%d",&n);
		for (int i=0; i<n; i++) {
			scanf("%lf",&vet[i]);	S += vet[i];
		}
		
		m = S / double(n);	m = 2.0 * m;
		
		printf("Case #%d:",nteste++);
		
		for (int i=0; i<n; i++) {
			printf(" %.6lf",(m-vet[i])/S * 100.0);
		}
		printf("\n");
	}
	
	return 0;
}