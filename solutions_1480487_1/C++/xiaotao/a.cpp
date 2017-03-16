#include <cstdio>
#include <algorithm>
using namespace std;
struct Node {double y; int x,p;} a[201];

bool cmpx(Node a,Node b) {return a.x<b.x;}
bool cmpp(Node a,Node b) {return a.p<b.p;}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,t,n,i,j,sum;
	double d,s;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d",&n);
		sum=0;
		for (i=0; i<n; ++i)
		{
			scanf("%d",&a[i].x);
			sum+=a[i].x;
			a[i].y=a[i].x;
			a[i].p=i;
		}
		s=sum;
		sort(a,a+n,cmpx);
		a[n].y=10000.0;
		for (i=1; i<=n && s>0.0; ++i)
		{
			d=min(a[i].y-a[i-1].y,s/i);
			for (j=0; j<i; ++j) a[j].y+=d;
			s-=d*i;
		}
		sort(a,a+n,cmpp);
		printf("Case #%d:",t);
		for (i=0; i<n; ++i) printf(" %.6f",(a[i].y-a[i].x)/sum*100.0);
		printf("\n");
	}
	return 0;
}
