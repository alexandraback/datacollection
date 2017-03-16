#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d",&T);
	for(int test=1; test<=T; ++test) {
		int n, a[60][60];
		long long m;
		memset(a, 0, sizeof(a));
		scanf("%d%lld", &n, &m);
		printf("Case #%d: ", test);
		if(m > (1LL<<(n-2))) {
			printf("IMPOSSIBLE\n");
			continue;
		} else printf("POSSIBLE\n");
		if(m == (1LL<<(n-2))) {
			for(int i=0; i<n; ++i)
				for(int j=i+1; j<n; ++j)
					a[i][j] = 1;
		}
		else {
			for(int i=0; i<n-1; ++i)
				for(int j=i+1; j<n-1; ++j)
					a[i][j] = 1;
			for(int i=0; i<n; ++i)
				if(m & (1LL << i)) {
					if(i == 0) a[0][n-1] = 1;
					else a[i+1][n-1] = 1;
				}
		}
		for(int i=0; i<n; ++i) {
			
			for(int j=0; j<n; ++j) 
				printf("%d", a[i][j]);
			printf("\n");
		}
		/*int f[60];
		f[0]=1;
		for(int i=1; i<n; ++i) {
			f[i]=0;
			for(int j=0; j<i; ++j)
				if(a[j][i])
					f[i] += f[j];
		}
		printf("%d\n", f[n-1]);*/
	}
	return 0;
}
