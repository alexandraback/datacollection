#include <algorithm>
#include <cstdio>

using namespace std;

int mote[110];

int main() {

	int test;
	scanf("%d", &test);
	
	for(int k = 1; k <= test; k++) {
		printf("Case #%d: ", k);
		
		int n, a;
		scanf("%d %d", &a, &n);
		
		for(int i = 0; i < n; i++) {
			scanf("%d", mote+i);
		}
		
		if(a == 1) {
			printf("%d\n", n);
			continue;
		}
		
		sort(mote, mote+n);
		
		int mi = n;
		
		int mov = 0;
		
		for(int i = 0; i < n; i++) {
			if(a > mote[i]) {
				a+= mote[i];
			} else {
				mi = min(mov+n-i, mi);
				while(a <= mote[i]) {
					a = 2*a - 1;
					mov++;
				}
				a += mote[i];
			}
		}
		
		mi = min(mov, mi);
		
		printf("%d\n", mi);
	}

	return 0;
}
