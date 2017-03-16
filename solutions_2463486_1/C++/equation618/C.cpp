#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int s[10000005],a[105];

bool check(ll t)
{
	int l=0;
	for (;t; t/=10) a[++l]=t%10;
	for (int i=1; i+i<=l; i++) if (a[i]!=a[l-i+1]) return 0;
	return 1;
}

void work()
{
	for (int i=1; i<10000005; i++) if (check(i))
	{
		ll t=1ll*i*i;
		s[i]=s[i-1]+check(t);
	}
	else s[i]=s[i-1];
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	ll l,r;
	work(),scanf("%d",&T);
	for (int i=1; i<=T; i++) scanf("%I64d%I64d",&l,&r),printf("Case #%d: %d\n",i,s[(int)sqrt(r)]-s[(int)sqrt(l-1)]);
	//system("pause");
	return 0;
}
