#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int c[5000];
int main() {
	int T, ics = 0;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<=3000; ++i)
			c[i] = 0;
		for(int i=0; i<(2*n-1); ++i) {
			for(int j=0; j<n; ++j) {
				int x;
				scanf("%d", &x);
				c[x] ++;
			}
		}
		printf("Case #%d:", ++ics);
		for(int i=0; i<=2500; ++i) if( c[i] % 2 == 1 ) {
			printf(" %d", i);
		}
		puts("");
	}
	return 0;
}
