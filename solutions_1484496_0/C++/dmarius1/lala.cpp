#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int suma[2000001], n;
int val[501];

void afisare(int a) {
	vector<int> sol;
	for( int j = 0; j < n; ++j) {
		if( a & ( 1<<j))
			sol.push_back(j+1);
			
	}
	int i;
	for( i = 0; i < sol.size() - 1; ++i)
		printf("%d ", val[sol[i]]);
	printf("%d\n", val[sol[i]]);
}

int main() {
	
	freopen("equal.in", "r", stdin);
	freopen("equal.out", "w", stdout);
	
	int tt;
	scanf("%d", &tt);
	
	for( int ii = 1; ii <= tt; ++ii) {
		
		printf("Case #%d:\n", ii);
		memset(suma, 0, sizeof(suma));
	
		scanf("%d", &n);
		for( int i = 1; i <= n; ++i) {
			scanf("%ld", &val[i]);
		}
		
		for( int i = 0 ; i < (1<<n); ++i) {
			int sum = 0;
			for( int j = 0; j < n; ++j) {
				if( i & ( 1<<j))
					sum += val[j+1];
			}
			if(suma[sum] == 0) {
				suma[sum] = i;
			}
			else {
				afisare(i);
				afisare(suma[sum]);
				break;
			}
		}
	}
}
