#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long LL;
#define N 110
int n, T, a[N], x, re;

int main()
{
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		cin>>re>>n;
		for (int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		LL ans=0x7ffffff;
		for (int i=n;i>=0;i--)
		{
			LL tmp=n-i;
			x=re;
			for (int j=0;j<i;j++)
				if (x>a[j]) x+=a[j];
				else 
				{
					if (x==1) { tmp=0x7fffffff; break; }
					while (x<=a[j]) tmp++, x+=x-1;
					x+=a[j];
				}
			ans=min(tmp,ans);
		}
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}