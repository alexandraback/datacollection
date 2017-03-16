#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t,tt,n,ans;
int a[110],f[110];
long long now;

void work()
{
	cin >>now >>n;
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	ans=n;
	if (now!=1)
	{
		f[0]=0;
		for (int i=1;i<=n;++i)
		{
			f[i]=f[i-1];
			while (now<=a[i])
			{
				++f[i];
				now+=now-1;
			}
			now+=a[i];
		}
		for (int i=1;i<=n;++i) ans=min(ans,f[i]+n-i);
	}
	printf("Case #%d: %d\n",tt,ans);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
