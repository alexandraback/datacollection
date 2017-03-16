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

const int maxn = 1e7 + 10;
//const int maxn = 100;
LL sum[maxn];
LL aa[41]={0,1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001};
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
	cout<<1<<','<<endl;
	for (LL i = 2; i < maxn ; ++i)
	{
		sum[i] = sum[i - 1];
		if (ok(i) && ok(i * i))
		{
			sum[i] ++;
			cout << i <<',';
		}
	}
	cout<<endl;
	cout<<"END"<<endl;
}


int main()
{
	//init();
//	freopen("bb.in","r",stdin);
//	freopen("bb.out","w",stdout);
	scanf("%d",&t);
	for (int cas = 1; cas <= t; ++cas)
	{
		LL ans = 0;
		LL a,b,l,r;
	 	scanf("%I64d%I64d",&a,&b);
	 	//cin>>a>>b;
	//	l = (long long) (sqrt(a));
	//	r = (long long) (sqrt(b));
		int i = 1,j = 40;
		while(i < 42)
		{
			if (aa[i] * aa[i] >= a) break;
			i++;
		}
		i --;
	//	cout <<i <<endl;
		while (j >= 1 )
		{
			if (aa[j] * aa[j] <= b) break;
			j --;
		}
	//	cout<<j<<endl;
		printf("Case #%d: ",cas);
		printf("%d\n",j-i);
	}
    return 0;
}
