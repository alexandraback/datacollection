#include <cstdio>
#include <cstring>

using namespace std;
#define rep(i,l,r) for (int i=(l);i<=(r);i++)

const int maxn=1020;
int a[maxn];
int n,ans,tot;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		scanf("%d ",&n);
		int sum=0;
		rep(i,0,n) {
			char ch;
			scanf("%c",&ch);
			a[i]=ch-48;
			sum+=a[i];
		}
		scanf("\n");
		ans=-1;
		rep(i,0,n) {
			tot=i;
			rep(j,0,n) {
				if (tot>=j)
					tot+=a[j];
			}
			if (tot==sum+i) {
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
