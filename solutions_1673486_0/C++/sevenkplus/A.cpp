#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
int n,m;double a[N];
int main()
{
	int _;scanf("%d",&_);
	for(int __=1;__<=_;__++)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%lf",a+i);
		double S=m+2;double T=1;
		for(int i=0;i<n;i++)
			T*=a[i],S=min(S,n-1-i+(m-1-i)+1+(1-T)*(m+1));
		printf("Case #%d: %.9lf\n",__,S);
	}
	return 0;
}
