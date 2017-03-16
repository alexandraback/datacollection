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
LL work(LL a)
{
	LL res=0;
	LL i=0;
	while (true)
	{
		if (i*i>a)
			break;
		LL j=0,k=i;
		while (k>0)
		{
			j=j*10+k%10;
			k/=10;
		}
		if (j!=i)
		{
			i++;
			continue;
		}
		j=0;k=i*i;
		while (k>0)
		{
			j=j*10+k%10;
			k/=10;
		}
		if (j==i*i)
			res++;
		i++;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	LL a,b;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		cin>>a>>b;
		cout<<(work(b)-work(a-1))<<"\n";
	}
}