#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 10100
using namespace std;

int A[maxn],que[maxn],f[maxn],dot[maxn],du[maxn];
int T,t;

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for (scanf("%d",&T), t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		int n;
		scanf("%d",&n); int ans = 0;
		for (int i = 1; i <= n; i++) scanf("%d",&A[i]);
		memset(du,0,sizeof(du));
		memset(f,0,sizeof(f));
		for (int i = 1; i <= n; i++) du[A[i]]++;
		int L = 0, R = 0;
		for (int i = 1; i <= n; i++)
			if (!du[i]) que[++R] = i;
		for (; L < R; ) {
			int u = que[++L];
			du[A[u]]--; f[A[u]] = max(f[A[u]],f[u] + 1);
			if (!du[A[u]]) que[++R] = A[u];
		}
		int top = 0,js = 0;		
		for (int i = 1; i <= n; i++) {
			if (!du[i]) continue;
			top = 0;
			int u = i; du[u]--;
			dot[++top] = u;
			for (int v = A[u]; v != u; v = A[v]) du[v]--, dot[++top] = v;
			if (top > 2) ans = max(ans,top);
			else js += 2 + f[dot[1]] + f[dot[2]];			
		}
		printf("%d\n",max(ans,js));
	}
	return 0;
}
