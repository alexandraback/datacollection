#include<bits/stdc++.h> 

using namespace std;

typedef pair<int, int> PII;

int main(){
	freopen("Bs.in", "r", stdin);
	freopen("Bs.out", "w", stdout);
	int T; cin>>T;
	for(int o = 1; o <= T; o++){
		long long n,m;
		printf("Case #%d: ", o);
		scanf("%lld%lld", &n, &m);
		if ((1LL << (n - 2)) < m)
			puts("IMPOSSIBLE");
		else{
			puts("POSSIBLE");
			m--;
			putchar('0');
			for(int i = n - 3; i >= 0; i--)
				if ((m >> i) & 1)
					putchar('1');
				else
					putchar('0');
			puts("1");
			for(int i = 2; i <= n; i++){
				for(int j = 1; j <= n; j++)
					printf("%d", (i < j));
				puts("");
			}
		}
	}
	return 0;
}
