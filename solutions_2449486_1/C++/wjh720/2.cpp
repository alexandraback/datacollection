#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int x,y,a;
} a[10010];
int i,j,k,n,m,T,cnt;
int b[110][110],c[110],d[110];
inline bool cc1(const ww &a,const ww &b) {
	return a.a<b.a;
}
int main() {
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	For(k,1,T) {
		printf("Case #%d: ",k);
		scanf("%d%d",&n,&m); cnt=0;
		For(i,1,n)For(j,1,m) {
			scanf("%d",&b[i][j]);
			a[++cnt].x=i,a[cnt].y=j,a[cnt].a=b[i][j];
			c[i]=j==1?b[i][j]:max(c[i],b[i][j]);
		}
		For(j,1,m)For(i,1,n) d[j]=i==1?b[i][j]:max(d[j],b[i][j]);
		sort(a+1,a+cnt+1,cc1); int F=1;
		For(i,1,cnt) if (c[a[i].x]>a[i].a&&d[a[i].y]>a[i].a) {
			F=0; break;
		}
		printf("%s\n",F?"YES":"NO");
	} return 0;
}
