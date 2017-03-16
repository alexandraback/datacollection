#pragma comment(linker, "/STACK:36777216")
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL long long
LL work(LL pos)
{
	LL a,b;
	LL res=0;
	for (LL i=0;i*i<=pos;i++)
	{
		a=0;
		b=i;
		while (b)
		{
			a=a*10+b%10;
			b/=10;
		}
		if (a!=i)
			continue;
		a=0;
		b=i*i;
		while (b)
		{
			a=a*10+b%10;
			b/=10;
		}
		if (a==i*i)
			res++;
	}
	return res;
}
LL work2(LL i)
{
	LL res=0;
	if (i>=0) res++;
	if (i>=1) res++;
	if (i>=4) res++;
	if (i>=9) res++;
	if (i>=121) res++;
	if (i>=484) res++;
	if (i>=10201) res++;
	if (i>=12321) res++;
	if (i>=14641) res++;
	if (i>=40804) res++;
	if (i>=44944) res++;
	if (i>=1002001) res++;
	if (i>=1234321) res++;
	if (i>=4008004) res++;
	if (i>=100020001) res++;
	if (i>=102030201) res++;
	if (i>=104060401) res++;
	if (i>=121242121) res++;
	if (i>=123454321) res++;
	if (i>=125686521) res++;
	if (i>=400080004) res++;
	if (i>=404090404) res++;
	if (i>=10000200001) res++;
	if (i>=10221412201) res++;
	if (i>=12102420121) res++;
	if (i>=12345654321) res++;
	if (i>=40000800004) res++;
	if (i>=1000002000001) res++;
	if (i>=1002003002001) res++;
	if (i>=1004006004001) res++;
	if (i>=1020304030201) res++;
	if (i>=1022325232201) res++;
	if (i>=1024348434201) res++;
	if (i>=1210024200121) res++;
	if (i>=1212225222121) res++;
	if (i>=1214428244121) res++;
	if (i>=1232346432321) res++;
	if (i>=1234567654321) res++;
	if (i>=4000008000004) res++;
	if (i>=4004009004004) res++;
	if (i>=100000020000001) res++;
	if (i>=100220141022001) res++;
	if (i>=102012040210201) res++;
	if (i>=102234363432201) res++;
	if (i>=121000242000121) res++;
	if (i>=121242363242121) res++;
	if (i>=123212464212321) res++;
	if (i>=123456787654321) res++;
	if (i>=400000080000004) res++;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("C-large-1.in","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	LL T,a,b;
	cin>>T;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		cin>>a>>b;
		if (a>b)
			swap(a,b);
		//work(b);
		cout<<(work2(b)-work2(a-1))<<"\n";
	}
}