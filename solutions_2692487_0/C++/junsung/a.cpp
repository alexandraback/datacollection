#include <stdio.h>
#include <stdlib.h>

int compare(const void *d1, const void *d2) {
	int num1 = *((int *)d1);
	int num2 = *((int *)d2);

	if(num1 < num2)
		return -1;
	else if(num1 > num2)
		return 1;
	else
		return 0;
}

int data[101];

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		int a, n;
		scanf("%d %d", &a, &n);
		for(int j = 0; j < n; j++) {
			scanf("%d", &data[j]);
		}

		qsort(data, n, sizeof(int), compare);

		int num = a;
		int count = 0;
		int min = 2000000000;
		for(int j = 0; j < n; j++) {
			if(data[j] < num) {
				num += data[j];
			}
			else {
				if(min > (count+(n-j))) {
					min = count+(n-j);
				}
				
				if(num-1 == 0) {
					count = 2000000000;
					break;
				}

				while(num <= data[j]) {
					num += (num-1);
					count++;
				}

				num += data[j];
			}
		}

		if(min > count)
			min = count;

		printf("Case #%d: %d\n", (i+1), min);
	}

	return 1;
}