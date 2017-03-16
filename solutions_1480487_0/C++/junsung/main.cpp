#include <stdio.h>


int main() {
	int t, n;
	scanf("%d", &t);

	
	int i = 0;
	for(i = 0; i < t; i++) {
		scanf("%d", &n);
		int j = 0;
		int sum = 0;
		int data[202];
		int max = -1;
		for(j = 0; j < n; j++) {
			scanf("%d", &data[j]);
			sum += data[j];
		}
		double average;
		int temp_n = n;
		int temp_sum = sum;
		while(1) {
			average = (double)(temp_sum+sum) / (double)temp_n;
		
			temp_sum = 0;
			temp_n = 0;
			int k = 0;
			int flag = 0;
			for(k = 0; k < n; k++) {
				if(data[k] > average) {
					data[k] = -1;
					flag = 1;
				}
				else {
					temp_sum += data[k];
					temp_n++;
				}
			}

			if(flag == 0)
				break;
		}
		

		printf("Case #%d:", i+1);
		for(j = 0; j < n; j++) {
			if(data[j] == -1) {
				printf(" 0.000000");
			}
			else {
				double y = (average - data[j]) / sum * 100;
				printf(" %.6lf", y);
			}
			
		}
		printf("\n");
	}

	return 0;
}