#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO(X) memset(X,0,sizeof(X))
#define FOR(I,N) for (I=0;I<(N);++I)
#define REV(I,N) for (I=(N)-1;I>=0;--I)
#define FORK(I,K,N) for (I=(K);I<(N);++I)
#define REVK(I,K,N) for (I=(K);I>=0;--I)
#define pb push_back
#define sci(d) scanf("%d",&d)
#define scll(l) scanf("%lld",&l)
#define scull(l) scanf("%llu",&l)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull x[]={1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 
  4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 
  400080004ULL, 404090404ULL, 10000200001ULL, 10221412201ULL, 12102420121ULL, 12345654321ULL, 
  40000800004ULL, 1000002000001ULL, 1002003002001ULL, 1004006004001ULL, 1020304030201ULL, 
  1022325232201ULL, 1024348434201ULL, 1210024200121ULL, 1212225222121ULL, 1214428244121ULL, 
  1232346432321ULL, 1234567654321ULL, 4000008000004ULL, 4004009004004ULL};
size_t xs=39;

/*
ull x[100],xs=0;
bool palindrome (ull n)
{
	char a[16];
	int i=0;
	while (n)
	{
		a[i]=n%10;
		n/=10;
		++i;
	}
	for (int j=0;j<i/2;++j)
		if (a[j]!=a[i-j-1]) return false;
	return true;
}

void fillx ()
{
	for (ull q=1;;++q)
	{
		ull qq=q*q;
		if (qq>100000000000000ULL) break;
		if (palindrome(q) && palindrome(qq))
			x[xs++]=qq;
	}
}*/

int main ()
{
	int t,i;
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d",&t);
	//fillx();
	FOR(i,t)
	{
		ull a,b;
		scanf("%llu %llu",&a,&b);
		printf("Case #%d: %ld\n",i+1,upper_bound(x,x+xs,b)-lower_bound(x,x+xs,a));
	}
	return 0;
}