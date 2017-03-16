// File Name: b.cpp
// Author: Missa
// Created Time: 2013/4/13 ÐÇÆÚÁù 12:13:27

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
#define CL(x,v) memset(x,v,sizeof(x));
#define R(i,st,en) for(int i=st;i<en;++i)
#define LL long long
#define inf 0x3f3f3f3f

//const int maxn = 1e7 + 10;
const int maxn = 100;
LL sum[maxn];
int t;
int tmp[20];

bool ok(LL x)
{
	LL c = x;
	int cnt = 0;
	while(c)
	{
		int tt= c%10;
		c/=10;
		tmp[cnt++] = tt;
	}
	for (int i = 0; i < cnt/2; ++i)
		if (tmp[i] != tmp[cnt-i - 1])
			return false;
	return true;
}

void init()
{
	sum[0] = 0;sum[1] = 1;
	for (LL i = 2; i < maxn ; ++i)
	{
		sum[i] = sum[i - 1];
		if (ok(i) && ok(i * i))
		{
			sum[i] ++;
			//cout << i <<endl;
		}
	}
}

int main()
{
	init();
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for (int cas = 1; cas <= t; ++cas)
	{
		LL ans = 0;
		LL a,b,l,r;
	 	scanf("%lld%lld",&a,&b);
		l = (long long) (sqrt(a));
		if (l * l == a && ok(l))
			ans ++;
		r = (long long) (sqrt(b));
		ans += sum[r] - sum[l];
		printf("Case #%d: ",cas);
		printf("%lld\n",ans);
	}
    return 0;
}
