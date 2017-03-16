#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	signed int t, x, y, i, j, k;
	scanf("%d", &t);

	for(j = 1; j <= t; j++) {
		scanf("%d %d", &x, &y);
		printf("Case #%d: ", j);

		if(x < 0) {
			for(i = 0; i < -x; i++) {
				printf("EW");
			}

			if(y < 0) {
				for(k = 0; k < -y; k++) {
					printf("NS");
				}
			} else {
				for(k = 0; k < y; k++) {
					printf("SN");
				}
			}

		} else  {
			for(i = 0; i < x; i++) {
				printf("WE");
			}

			if(y < 0) {
				for(k = 0; k < -y; k++) {
					printf("NS");
				}
			} else {
				for(k = 0; k < y; k++) {
					printf("SN");
				}
			}

		}
		printf("\n");
	}

	return 0;
}
