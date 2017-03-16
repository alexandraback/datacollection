#include "stdio.h"

int main ()
{
	int t;
	int i;
	scanf("%d", &t);

	for (i=0; i<t; i++) {
		int x,y,j;
		char* dir = NULL;
		scanf("%d %d", &x, &y);

		printf("Case #%d: ", i+1);

		if (x>0) {
			dir = "WE";
		}else{
			dir = "EW";
			x = -x;
		}

		for (j=0; j<x; j++) {
			printf("%s", dir);
		}
		
		if (y>0) {
			dir = "SN";
		}else{
			dir = "NS";
			y = -y;
		}

		for (j=0; j<y; j++) {
			printf("%s", dir);
		}
		printf("\n");
	}
	return 0;
}
