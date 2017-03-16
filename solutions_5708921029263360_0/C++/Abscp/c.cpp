#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
int a[2000], b[2000], c[2000];
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d",&T);
	for(int test=1; test<=T; ++test) {
		int n, m, k, t, ans = 0;
		int ok2[1000], ok3[1000], ok4[1000];
		scanf("%d%d%d%d",&n, &m, &k, &t);
		memset(ok2, 0, sizeof(ok2));
		memset(ok3, 0, sizeof(ok3));
		memset(ok4, 0, sizeof(ok4));
		printf("Case #%d: ", test);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				for(int l=0; l<k; ++l)
					if(ok2[i*10 + j] < t && ok3[i*10 + l] < t && ok4[j*10 + l] < t) {
						a[ans] = i;
						b[ans] = j;
						c[ans++] = l;
						ok2[i*10 + j] ++;
						ok3[i*10 + l] ++;
						ok4[j*10 + l] ++;
					}
		printf("%d\n", ans);
		for(int i=0; i<ans; ++i)
			printf("%d %d %d\n", a[i]+1, b[i]+1, c[i]+1);
		
	}
	return 0;
}
