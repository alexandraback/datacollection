#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);


	int _n;
	scanf("%d", &_n);

	for (int _t=1; _t<=_n; _t++) {
		int n, m, k=0, C[3000] = {0}, Ret[55] = {0};
		scanf("%d", &n);
		for (int i=1; i<=2*n-1; i++) {
			for (int j=1; j<=n; j++) {
				scanf("%d", &m);
				C[m]++;
				if (k < m) { k = m; }
			}
		}
		for (int i=1, j=0; i<=k; i++) {
			if (C[i] & 1) { Ret[++j] = i; }
		}
		sort(Ret+1, Ret+1+n);

		printf("Case #%d:", _t);
		for (int i=1; i<=n; i++) {
			printf(" %d", Ret[i]);
		}
		printf("\n");

	}
}
