#include <bits/stdc++.h>
using namespace std;

int N,a[1005];

int work(int x)
{
	int s=0;
	for (int i=1; i<=N; i++) if (a[i]>x) s+=(a[i]+x-1)/x-1;
	return s;
}

int calc()
{
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&a[i]);
	int ans=1e9;
	for (int i=1; i<=1000; i++) ans=min(ans,i+work(i));
	return ans;
}

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++) printf("Case #%d: %d\n",i,calc());
	return 0;
}

