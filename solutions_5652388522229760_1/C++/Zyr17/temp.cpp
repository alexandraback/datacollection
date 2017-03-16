#include <bits/stdc++.h>
#define Init freopen("t.in","r",stdin);freopen("t.out","w",stdout);
int n,m;
int main(){
	Init;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ ){
		printf("Case #%d: ", i);
		scanf("%d", &m);
		if (!m) printf("INSOMNIA\n");
		else{
			bool pd[10] = {0};
			int t = m;
			for (; ; ){
				for (int i = t; i; i /= 10)
					pd[i % 10] = 1;
				for (int i = 0; i < 10; i ++ )
					if (!pd[i]) goto aaa;
				printf("%d\n", t);
				break;
				aaa:;
				t += m;
			}
		}
	}
}
