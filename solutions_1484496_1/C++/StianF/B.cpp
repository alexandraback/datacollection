#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int t;
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		printf("Case #%d:\n", i+1);
		scanf("%d", &n);
		int numbers[n];

		for(int j = 0; j < n; j++){
			scanf("%d", &numbers[j]);
		}

		long long int n_comb = pow(2, n)-1;
		int i_comb = 0;
		int sums[n_comb];
		bool done = false;
		for(int j = 0; j < n_comb; j++){
			int sum = 0;
			for(int k = 0; k < n; k++){
				if(j&(1<<k))
					sum += numbers[k];
			}
			sums[j] = sum;
			for(int k = 0; k < j; k++){
				if(sum == sums[k]){
					for(int l = 0; l < n; l++){
						if(k & (1<<l))
							printf("%d ", numbers[l]);					
					}
					printf("\n");
					for(int l = 0; l < n; l++){
						if(j & (1<<l))
							printf("%d ", numbers[l]);					
					}
					printf("\n");
					done = true;
					break;
				}	
			}
			if(done)
				break;
		}
		if(!done)
			printf("Impossible\n");
	}
	return 0;
}
