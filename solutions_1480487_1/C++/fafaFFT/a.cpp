#include<cstdio>
#include<algorithm>
using namespace std;

int t,n,suma;
int oceny[300];
int main() {
	scanf("%d",&t);
	for(int ind = 1;ind<=t;ind++) {
		scanf("%d",&n);
		int suma = 0;
		for(int i=0;i<n;i++) {
			scanf("%d",&oceny[i]);
			suma += oceny[i];
		}
		printf("Case #%d: ", ind);
		for(int i=0;i<n;i++) {
			long double a=0,b=1,c;
			for(int k=0;k<100;k++) {
				c = (a+b)/2;
				double ile = oceny[i]+c*suma;
				double sumka = c;
				for(int l=0;l<n;l++) if(l!=i) {
					sumka += max(0.0L, (long double)(ile-oceny[l])/suma);
				}
				if(sumka <= 1) {
					a=c;
				}
				else b=c;
			}
			//long double wynik = (2.0*suma-oceny[i]*n)/(long double)(suma*n);
			//printf("%.10lf ", max(0.0,(double)wynik*100));
			printf("%.8lf ", (double)(c*100));
		}
		printf("\n");
	}
	return 0;
}
