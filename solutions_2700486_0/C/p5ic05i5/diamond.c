#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, X, Y;
int w[20002][10001];
long long int ok;
long long int tot;

int get(int x, int y) {
	return w[x+10000][10000-y];
}

void set(int x, int y) {
	w[x+10000][10000-y] = 1;
}

void unset(int x, int y) {
	w[x+10000][10000-y] = 0;
}

int tallest(int x) {
	int i;
	for ( i = 0 ; i <= 10000 ; ++i )
		if ( get(x, i) == 0 )
			return i-1;
	return Y;
}

void fall(int n, int x, int y);

void landed(int n, int x, int y) {

	//tot++;
//	printf("landed %d: %d %d", n, x, y);
	set(x, y);
	//printf("\n");
	fall(n-1, 0, 10000);
	unset(x, y);
}

void fall(int n, int x, int y) {

	if ( n <= 0 ) {
		tot++;
		if ( get(X, Y) ) {
	//		printf(" (ok %d %d)\n", X, Y);
			ok++;
		}
		return;
	}
		

//	printf("falling %d (%d, %d)\n", n, x, y);
		
	int left = tallest(x-1);
	int center = tallest(x);
	int right = tallest(x+1);
	
//	printf("left %d, center %d, right %d\n", left, center, right);
	
	// Ground hit
	if ( center == -1 && left == -1 && right == -1) {
		landed(n, x, 0);
		return;
	}
	
	// Pyramid tip
	if ( center > left && center > right ) {
		fall(n, x-1, center+1);
		fall(n, x+1, center+1);
		return;
	}
	
	// Sinkhole
	if ( left == right ) {
		landed(n, x, left+1);
		return;
	}
	
	// Fall right
	if ( right < left )
		return fall(n, x+1, left);
		
	// Fall left
	if ( left < right )
		return fall(n, x-1, right);
	
	printf("error!!\n");
	
}

int main() {
	int i, t, x = 1;
	scanf("%d\n", &t);
	while ( t-- ) {
		scanf("%d %d %d\n", &n, &X, &Y);
		ok = tot = 0;
		memset(&w, 0, sizeof(w));
		fall(n, 0, 10000);
		printf("Case #%d: %lf\n", x++, (double) ((double)ok / (double)tot));
	}
	return 0;
}

