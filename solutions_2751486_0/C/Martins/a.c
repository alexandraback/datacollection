#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T, n, value, i, j, k, l, m;
	char name[10000];
	
	scanf("%d", &T);

	for(i = 0; i < T; i++) {
		scanf("%s %d", name, &n);

		value = 0;
		int temp, temp2;
		int length = strlen(name);
		for(j = 0; j < length; j++) {
			for(k = j+n-1; k < length; k++) {
				for(l = j; l <= k && k-l >= n-1; l++) {
					for(m = l, temp = 0, temp2 = 0; m <= l+n-1; m++) {
						if(name[m] != 'a' && name[m] != 'e' && name[m] != 'i' && name[m] != 'o' && name[m] != 'u') {
							temp++;
						}
					}
					if(temp >= n) {
						temp2 = 1;
						break;
					}
				}
				if(temp2) {
					value++;
				}
			}
		}




		printf("Case #%d: %d\n", i+1, value);
	}

	return 0;
}
