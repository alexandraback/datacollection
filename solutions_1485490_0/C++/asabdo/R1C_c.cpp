#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<climits>
#include<set>
#include<iterator>
#include<complex>
#ifdef _MSC_VER
#include <hash_set>
#include <hash_map>
using namespace stdext;
#else
#if __GNUC__ > 2
#include <ext/hash_set>
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_set>
#include <hash_map>
#endif
#endif
using namespace std;

int N,M;
long long tot;
long long best;
long long a[101],b[101];
int ta[101],tb[101];
long long f(int i,int j)
{
	if( i == N || j == M)
		return 0;
	long long x=0;
	if( ta[i] == tb[j] )
	{
		x = min(a[i],b[j]);
	}

	a[i] -= x;
	b[j] -= x;
	tot+=x;
	best = max(best,tot);
	f(i+1,j);
	f(i,j+1);
	f(i+1,j+1);
	tot-=x;
	b[j]+=x;
	a[i]+=x;
}


long long bb[101];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","rt",stdin);
	freopen("cout.txt","wt",stdout);
#endif
	int TC=1;
	scanf("%d",&TC);
	int m,x;
	for(int tc=1;tc<=TC;tc++)
	{
		cerr<<tc<<endl;
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++)
			scanf("%lld %d",a+i,ta+i);
		for(int j=0;j<M;j++)
			scanf("%lld %d",b+j,tb+j);
		best = 0;
		f(0,0);

		printf("Case #%d: %lld\n",tc,best);
	}
	return 0;
}