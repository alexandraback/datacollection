#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define maxlongint 2147483647
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

double a[1010],b[1010];
int T,n,cs=0;

int main()
{
	freopen("123.in","r",stdin);
	freopen("123.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lf",&b[i]);
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		printf("Case #%d: ",++cs);
		int ans1=0,ans2=0,wb=1;
		for(int i=1;i<=n;i++)
		{
			bool flag=false;
			while(wb<=n)
			{
				if(b[wb]>a[i]){wb++;flag=true;break;}
				wb++;
			}
			if(!flag)ans1++;
		}
		int lb=1,rb=1;
		for(int i=1;i<=n;i++)
			if(a[i]<b[lb])
				rb--;
			else
			{
				ans2++;
				lb++;
			}
		printf("%d %d\n",ans2,ans1);
	}
	return 0;
}
