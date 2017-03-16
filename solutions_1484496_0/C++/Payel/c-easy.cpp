#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 20;

typedef pair< int, int > pii;

int main() {
	int test, cs, n, i, j, a[MAX], sum, f;
	map< int, vector< int > > M;
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		M.clear();
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		printf("Case #%d:\n", cs);
		for(i = 0; i < (1 << n); i++) {
			for(j = sum = 0; j < n; j++)
				if(i & (1 << j)) sum += a[j];
			M[sum].push_back(i);
			if(M[sum].size() >= 2) {
				i = M[sum][0];
				for(j = f = 0; j < n; j++) {
					if(i & (1 << j)) {
						if(f) printf(" ");
						printf("%d", a[j]);
						f = 1;
					}
				}
				printf("\n");
				i = M[sum][1];
				for(j = f = 0; j < n; j++) {
					if(i & (1 << j)) {
						if(f) printf(" ");
						printf("%d", a[j]);
						f = 1;
					}
				}
				printf("\n");
				n = -1;
				break;
			}
		}
		if(n != -1) puts("Impossible");
	}
	return 0;
}