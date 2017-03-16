#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

	
int main() {
	int t;
	cin >> t;
	for (int tcase = 1; tcase <= t; tcase ++){
		int n;
		scanf("%d ", &n);
		int vet[2505];
		for (int i = 0; i <= 2502; i++)
			vet[i] = 0;
			
		int maxi = 0;
		
		for (int i = 0; i < 2 * n - 1; i++) {
			vector <int> temp;
			int x;
			for (int j = 0; j < n; j++) {
				scanf("%d ", &x);
				vet[x]++;
			}
			if (x > maxi)
				maxi = x;
		}
		vector <int> res;
		for (int i = 0; i<= maxi; i++) 
			if (vet[i] % 2 == 1)
				res.push_back(i);
		sort(res.begin(), res.end());

		printf("Case #%d: ", tcase);
		for (int i = 0; i < n; i++)
			printf("%d ", res[i]);
		printf("\n");
		
		
	}
	return 0;
}
