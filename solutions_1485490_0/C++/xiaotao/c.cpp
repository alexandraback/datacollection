#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
struct Node {int x; LL k;} a[101],b[101];
int n,m;

LL work1(int p,int l,int r)
{
	LL s=0;
	for (int i=l; i<=r; ++i)
		if (b[i].x==a[p].x) s+=b[i].k;
	return min(s,a[p].k);
}

LL work2()
{
	LL s=0;
	for (int i=0; i<=m; ++i) s=max(s,work1(1,1,i)+work1(2,i+1,m));
	return s;
}

LL work3()
{
	LL s=0;
	for (int i=0; i<=m; ++i)
		for (int j=i; j<=m; ++j) s=max(s,work1(1,1,i)+work1(2,i+1,j)+work1(3,j+1,m));
	if (a[1].x==a[3].x) a[1].k+=a[3].k, s=max(s,work1(1,1,m));
	return s;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,t,i,nn;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d%d",&n,&m);
		for (i=1; i<=n; ++i) scanf("%I64d%d",&a[i].k,&a[i].x);
		for (i=1; i<=m; ++i) scanf("%I64d%d",&b[i].k,&b[i].x);
		nn=1;
		for (i=2; i<=n; ++i)
			if (a[i].x==a[nn].x) a[nn].k+=a[i].k;
			else a[++nn]=a[i];
		n=nn;
		printf("Case #%d: ",t);
		if (n==1) printf("%I64d\n",work1(1,1,m)); else
		if (n==2) printf("%I64d\n",work2()); else printf("%I64d\n",work3());
	}
	return 0;
}
