#include <cstdio>
#include <cstring>
int T,n,m,left,min,mx,my,a[1005][1005];
bool p[1005][1005],bo,can,ans;
int main() {
	//freopen("b.in","r",stdin); freopen("b.out","w",stdout);
	scanf("%d",&T);
	for (int I = 1; I <= T; ++I) {
		scanf("%d%d",&n,&m); ans = true; left = n * m;
		memset(p,0,sizeof(p));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d",&a[i][j]);
		do {
			min = 101; can = false;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					if (!p[i][j] && a[i][j] < min) min = a[i][j],mx = i,my = j;
			
			bo = true;
			for (int j = 1; j <= m; ++j)
				if (!p[mx][j] && a[mx][j] > a[mx][my]) {bo = false; break;}
			if (bo) {
				can = true;
				for (int j = 1; j <= m; ++j)
					if (!p[mx][j]) --left,p[mx][j] = true;
			}
			
			bo = true;
			for (int i = 1; i <= n; ++i)
				if (!p[i][my] && a[i][my] > a[mx][my]) {bo = false; break;}
			if (bo) {
				can = true;
				for (int i = 1; i <= n; ++i)
					if (!p[i][my]) --left,p[i][my] = true;
			}
			if (!can) {ans = false; break;}
		} while (left != 0);
		if (ans) printf("Case #%d: YES\n",I);
		else printf("Case #%d: NO\n",I);
	}
}