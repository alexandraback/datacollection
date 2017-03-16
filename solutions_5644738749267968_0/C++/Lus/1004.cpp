// by team4
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
int ca=1;
int n,t;
#define maxn 1009
double a[maxn],b[maxn];
int main()
{

	scanf("%d",&t);
	while(t--)
	{
		int ans1=0,ans2=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i) scanf("%lf",&a[i]);
		for(int i=0;i<n;++i) scanf("%lf",&b[i]);
		sort(a,a+n);
		sort(b,b+n);
		int l=0;
		for(int i=0;i<n;++i)
		{
			if(b[i]>a[l]) 
			{
				++l;
				++ans1;
			}
		}
		l=0;
		for(int i=0;i<n;++i)
		{
			if(a[i]>b[l])
			{
				++l;
				++ans2;
			}
		}
		printf("Case #%d: ",ca++);
		printf("%d %d\n",ans2,n-ans1);
	}
	return 0;
}
