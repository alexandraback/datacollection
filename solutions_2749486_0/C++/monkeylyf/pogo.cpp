#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

int main() {
	int problem;
	setbuf(stdout, NULL);
	
	scanf("%d\n", &problem);
	
	for(int pi=0; pi<problem; pi++) {
		int X, Y;

		scanf("%d %d", &X, &Y);
		
		printf("Case #%d: ", pi+1);
		const char * X_str = X > 0 ? "WE" : "EW";
		const char * Y_str = Y > 0 ? "SN" : "NS";
		for(int i=0; i< (X > 0 ? X : -X); i++) printf(X_str);
		for(int i=0; i< (Y > 0 ? Y : -Y); i++) printf(Y_str);
		printf("\n");

	}
	return 0;
}
