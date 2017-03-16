//nathanajah's template
//28-11-2012
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#include <ctime>
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned LL
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFFFFFFFFFF
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(),(a).end()
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

inline string GetString()
{
	char GS[1000005];
	scanf("%s",GS);string ret=GS;
	return ret;
}

inline char getc()
{
	char c=' ';
	while (c==' ' || c=='\t' || c=='\r' || c=='\n')
		c=getchar();
	return c;
}
//ENDOFTEMPLATE

int t,a,n;
int i;
int arr[1000];

int bf(int l, int x)
{
	if (x==1)
		return n-l;
	int i=l;
	while (i<n)
	{
		if (arr[i]<x)
		{
			x+=arr[i];
		}
		else
			break;
		++i;
	}
	if (i==n)
		return 0;
	return min(n-i,1+bf(i,x+x-1));
}
int main()
{
	int aaaa;
	scanf("%d",&t);
	for (aaaa=0;aaaa<t;++aaaa)
	{
		scanf("%d",&a);
		scanf("%d",&n);
		for (i=0;i<n;++i)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		printf("Case #%d: %d\n",aaaa+1,bf(0,a));
	}
}
