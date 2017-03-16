#include <bits/stdc++.h>

int v[1010];
int numStalls[1010];

int main(){
	int t;
	scanf(" %d", &t);
	
	for(int k = 1; k <= t; k++){
		for(int i = 1; i < 1001; i++){
			v[i] = 0;
			numStalls[i] = 0;
		}
		int max = 0;
		int d, p;
		scanf(" %d", &d);
		for(int i = 0; i < d; i++){
			scanf(" %d", &p);
			if(p > max)
				max = p;
			v[p]++;
		}

		for(int i = 1; i <= max; i++){
			for(int j = 1; j < i; j++){
				int q = i/j;
				if(i%j == 0)
					q--;
				numStalls[j] += q*v[i];
			}
		}
		
		int min = max;
		
		for(int i = 1; i < max; i++){
			if(i+numStalls[i] < min)
				min = i+numStalls[i];
		}
		
		printf("Case #%d: %d\n", k, min);
	}
	return 0;
}