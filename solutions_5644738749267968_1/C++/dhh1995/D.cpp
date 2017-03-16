#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
typedef long long LL;
const int N=1005;
int T,Case,n; double a[N],b[N];
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		rep(i,n) scanf("%lf",a+i); sort(a,a+n),reverse(a,a+n);
		rep(i,n) scanf("%lf",b+i); sort(b,b+n),reverse(b,b+n);
		int j=0,s1=0,s2=n;
		rep(i,n){
			while (j<n && a[i]<b[j]) ++j;
			if (j<n && a[i]>b[j]) ++s1,++j;
		}
		j=0; rep(i,n) if (a[i]<b[j]) ++j,--s2;
		printf("Case #%d: %d %d\n",++Case,s1,s2);
	}
	return 0;
}

