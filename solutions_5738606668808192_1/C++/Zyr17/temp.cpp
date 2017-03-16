#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n,m,z[5555],ztot;
int main(){
	Init;
	int _;
	scanf("%d%d%d", &_, &n, &m);
	for (int i = 2; i <= 5000; i ++ ){
		bool pd = 1;
		for (int j = 1; j <= ztot && pd; j ++ )
			if (i % z[j] == 0) pd = 0;
		if (pd) z[ ++ ztot] = i;
	}
	for (int i = 1; i <= 1; i ++ ){
		printf("Case #%d:\n", i);
		int a[n + 1] = {0};
		int ans[11];
		a[0] = a[n - 1] = 1;
		for (; !a[n] && m; ){
			bool pd = 1;
			for (int i = 10; i >= 2 && pd; i -- ){
				for (int j = 1; j <= ztot; j ++ ){
					int tt = 0;
					for (int k = n - 1; k >= 0; k -- ){
						tt = tt * i + a[k];
						tt %= z[j];
					}
					if (!tt){
						ans[i] = z[j];
						goto End;
					}
				}
				pd = 0;
				End:;
			}
			if (pd){
				for (int i = n - 1; i >= 0; i -- ) printf("%d", a[i]);
				for (int i = 2; i <= 10; i ++ )
					printf(" %d", ans[i]);
				printf("\n");
				m -- ;
			}
			for (int i = 1; ++ a[i] == 2; a[i ++ ] = 0);
		}
	}
}
