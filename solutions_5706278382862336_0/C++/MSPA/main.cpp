#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

ll gcd(ll a, ll b)
{
	while (a && b)
		if (a>=b) a%=b;
		else b%=a;
	return a+b;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int countTests;
	scanf("%d",&countTests);
	for(int numTest=1;numTest<=countTests;++numTest)
	{
		ll p,q;
		scanf("%lld/%lld",&p,&q);
		ll g = gcd(p,q);
		p/=g;
		q/=g;

		printf("Case #%d: ", numTest);

		if (q & (q-1))
		{
			puts("impossible");
			continue;
		}
		ll ans = -1;
		ll a,b;
		b = q;
		a = 2*p - b;
		if (a>=0 && a<=b)
		{
			puts("1");
			continue;
		}
		for(ll i=1; ;++i)
		{
			if (2*p<=q)
			{
				if (~q&1)
					q>>=1;
				else p<<=1;
				ll a,b;
				b = q;
				a = 2*p - b;
				if (a>=0 && a<=b)
				{
					ans = i+1;
					break;
				}
			}
			else break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
