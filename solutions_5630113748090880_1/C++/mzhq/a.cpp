#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

int n;
const int N = 2505;
int vis[N];

int main() {
	int T, x;

	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		mst(vis, 0);
		scanf("%d", &n);
		For(i, n * 2 - 1)
			For(j, n) {
				scanf("%d", &x);
				vis[x]++;
			}
		printf("Case #%d: ", cas + 1);
		int tot = 0;
		For(i, N) if(vis[i] & 1) {
			if(tot++) printf(" ");
			printf("%d", i);
		}
		puts("");
	}

	return 0;
}
