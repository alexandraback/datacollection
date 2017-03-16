#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int t,ca;
int e,r,n;
long long ans;
int a[20];
long long f[20][20];

void work()
{
	cin >>e >>r >>n;
	for (int i=1;i<=n;++i) cin >>a[i];
	
	memset(f,0,sizeof(f));
	
	for (int i=1;i<=n;++i)
	{
		for (int j=0;j<=e;++j)
		{
			f[i][j]=max(f[i][j],f[i-1][j]);
			for (int k=0;k<=j;++k)
			{
				int p=min(e,j-k+r);
				f[i][p]=max(f[i][p],f[i-1][j]+k*a[i]);
			}
		}
	}
	
	ans=-1;
	for (int j=0;j<=e;++j) if (f[n][j]>ans) ans=f[n][j];
	
	printf("Case #%d: %lld\n",ca,ans);
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	cin >>t;
	for (ca=1;ca<=t;++ca) work();
	
	fclose(stdin);
    fclose(stdout);
    return 0;
}
