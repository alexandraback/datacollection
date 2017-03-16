#include <stdio.h>

int main() {
	char buffer[2000];
	int n, s, sum, req, i, j, k;

	scanf("%d", &n);
	for(i=0; i < n; i++) {
		scanf("%d%s", &s, buffer);
		//sum = 0;
		sum = buffer[0]-'0';
		req = 0;
		for(j=1; j <= s; j++)
			if(j > sum) {
				req += j-sum;
				sum += buffer[j]-'0'+j-sum;
			}
			else
				sum += buffer[j]-'0';
		printf("Case #%d: %d\n", i+1, req);
	}
}
