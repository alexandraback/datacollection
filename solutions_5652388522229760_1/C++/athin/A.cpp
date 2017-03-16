#include <bits/stdc++.h>

using namespace std;

long long t,n,i,done,x,y,tes;
bool yes[1000];

int main() {
	scanf("%lld",&t);
	for (tes=1 ; tes<=t ; tes++) {
		scanf("%lld",&n);
		printf("Case #%lld: ",tes);
		if (n == 0) printf("INSOMNIA\n"); else {
			for (i=0 ; i<10 ; i++) yes[i] = false;
			done = 0;
			
			x = 0;
			do {
				x += n;
				y = x;
				while (y > 0) {
					if (yes[y % 10] == false) {
						yes[y % 10] = true;
						done++;
					}
					y /= 10;
				}
			} while (done != 10);
			
			printf("%lld\n",x);
		}
	}
}