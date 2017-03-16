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

LL nod(LL a, LL b)
{
	while (a && b){
		if (a>b)
			a=a%b;
		else
			b=b%a;
	}
	return a+b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T;
	scanf("%d", &T);
	LL a, b,q;
	int l;
	forn(t,T)
	{
		scanf("%lld/%lld", &a, &b);
		q=nod(a,b);
		a/=q;
		b/=q;

		q=b;
		while (q%2==0)
			q/=2;
		if (q!=1)
		{
			printf("Case #%d: impossible\n",t+1);			
		}
		else
		{
			l=1;
			q=2;
			while (a*q<b)
			{
				q*=2;
				l++;
			}
			printf("Case #%d: ", t+1);
			printf("%d\n", l);
		}
	}

}