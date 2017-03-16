#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

int main() {
	int T, K, C, S;

	freopen("outd.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		scanf("%d%d%d", &K, &C, &S);
		int s = (K - 1)/ C + 1;
		//Debug(s);
		printf("Case #%d: ", cas + 1);
		if(s > S) {
			puts("IMPOSSIBLE");
			continue;
		}
		int x = 0;
		For(i, s) {
			ll val = 0;
			for(int j = 0; j < C; j++) {
				val *= K;
				val += x;
				x = (x + 1) % K;
			}
			if(i) printf(" ");
			printf("%lld", val + 1);
		}
		puts("");
	}
	return 0;
}
