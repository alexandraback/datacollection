#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
vector <double> a[2];

int main(){
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++){
		int n;
		scanf("%d", &n);
		for(int g = 0; g < 2; g++){
			a[g].resize(n);
			for(int i = 0; i < n; i++)
				scanf("%lf", &a[g][i]);
			sort(a[g].begin(), a[g].end());
		}
		printf("Case #%d:", test);
		for(int g = 0; g < 2; g++){
			int res = 0;
			int j = n - 1;
			for(int i = n - 1; i >= 0; i--)
				if(a[0][j] > a[1][i]){
					j--;
					res++;
				}
			if(g)
				printf(" %d", n - res);
			else
				printf(" %d", res);
			a[0].swap(a[1]);
		}
		puts("");
	}
}
