#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

const int maxn=1050,inf=~0u>>1;
int a[maxn];
int n,ans;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d\n",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		ans=inf;
		rep(i,1,1000) {
			int tmp=i;
			rep(j,1,n)
				tmp+=(a[j]-1)/i;
			if (ans>tmp) ans=tmp;
		}
		printf("%d\n",ans);
	}
	return 0;
}

