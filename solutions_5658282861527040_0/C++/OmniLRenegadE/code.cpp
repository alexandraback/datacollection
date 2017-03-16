#pragma comment(linker, "/STACK:64000000")
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (LL i=0;i<n;i++)
#define rforn(i,n) for (LL i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL long long

int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T;
	cin>>T;
	forn(t,T)
	{
		cout<<"Case #"<<(t+1)<<": ";
		LL res=0;
		int a, b, k;
		cin>>a>>b>>k;
		forn(i,a)
			forn(j,b)
				if ((i&j)<k)
					res++;
		cout<<res<<"\n";
	}

}