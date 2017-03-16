#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	freopen("output.txt","w",stdout);
	freopen("B-large.in","r",stdin);
	int T;
	cin >> T;
	int n, idx, counter;
	//int smallest;
	int input[5000];
	for (int t=1; t<=T; t++) {
		cin >> n;
		for (int i=0; i<2*n-1; i++) {
			for (int j=0; j<n; j++) {
				scanf("%d", &input[i*n+j]);
			}
		}
		sort(input, input+n*(2*n-1));
		//for (int i=0; i<n*(2*n-1); i++) 
		//	printf("%d ", input[i]);
		//printf("\n");
		idx = 0;
		counter = 0;
		printf("Case #%d: ", t);
		while (idx < n*(2*n-1)) {
			if (idx == n*(2*n-1)-1) {
				printf("%d\n", input[idx]);
				break;
			}
			if (input[idx] == input[idx+1]) {
				idx += 2;
			}else {
				printf("%d", input[idx]);
				counter++;
				if (counter == n) {
					printf("\n");
					break;
				}
				printf(" ");
				idx++;
			}
		}
	}
	return 0;
}