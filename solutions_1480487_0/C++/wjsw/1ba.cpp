#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int s[200];
bool p[200];
int main()
{
	freopen("in.in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		scanf("%d",&n);
		int a=0;
		for(int i = 0; i < n ; ++i)
		{
			scanf("%d",s+i);
			a+=s[i];
		}
		int b=a;
		a+=a;
		int m=n;
		memset(p,0,sizeof(p));
		for(int i = 0; i < n ; ++ i)for(int j = 0; j < n ; ++ j)if(!p[j])
		{
			if(a<=s[j]*m)
			{
				a-=s[j];
				--m;
				p[j]=true;
			}
		}
		printf("Case #%d:",tt);
		for(int i =0 ;i <n; ++i)
			if(p[i])printf(" %lf", 0.0);
			else printf(" %lf", 100.0*(1.0*a/m/b-1.0*s[i]/b));
		putchar('\n');
	}
	return 0;
}
