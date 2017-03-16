#include "stdio.h"
#include <string.h>

int main ()
{
	int t;
	int i;
	scanf("%d", &t);

	for (i=0; i<t; i++) {
		char name[101];
		int n;
		int j,k;
		int len = 0;
		scanf("%s %d", name, &n);
		
		len = strlen(name);

		int n_value = 0;

		for (j=0; j<len; j++) {
			int n_const = 0;
			int last_is_const = 0;
			int max_n_const = 0;


			for (k=j; k<len; k++) {
				int is_const = 1;

				switch (name[k]) {
					case 'a':
					case 'e':
					case 'i':
					case 'o':
					case 'u':
						is_const = 0;
						break;
				}

				if (is_const) {
					if (last_is_const) {
						n_const++;
					}else {
						n_const = 1;
					}

					if (n_const > max_n_const) {
						max_n_const = n_const;
					}	

					last_is_const = 1;
				}else{
					last_is_const = 0;
				}

				if (max_n_const >= n) {
					n_value++;

					/*
					char tmp = name[k+1];
					name[k+1] = 0;
					printf(">>%s\n",&name[j]);
					name[k+1] = tmp;
					*/
				}
			}
		}

		printf("Case #%d: %d\n", i+1, n_value);

	}
	return 0;
}
