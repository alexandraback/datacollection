#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int n,m,cnt,snt,times;
LL oo=1000000007;
double a[1010],c[1010],d[1010];
double b[1010];
bool ok(int x)
{
	if (x==0) return true;
	for (int i=1;i<=x;i++)
	if (b[i]>a[n-x+i]) return false;
	return true;
}
void work(int lab)
{
	printf("Case #%d: ",lab);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	memcpy(c,a,sizeof(a));
	memcpy(d,b,sizeof(b));
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int pos=-1;
		for (int j=1;j<=n;j++)
		if (b[j]>a[i])
		{
			pos=j;
			break;
		}
		if (pos!=-1) b[pos]=-1;
		else 
		{
			ans++;
			for (int j=1;j<=n;j++)
			if (b[j]>0)
			{
				b[j]=-1;break;
			}
		}
	}
	memcpy(a,c,sizeof(a));
	memcpy(b,d,sizeof(b));
	int l=0,r=n+1;
	while (l!=r)
	{
		int mid=(l+r)/2;
		if (ok(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d %d\n",l-1,ans);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	for (int i=1;i<=times;i++)
	work(i);
    return 0;
}

