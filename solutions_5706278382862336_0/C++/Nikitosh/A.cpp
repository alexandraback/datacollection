#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME "1"
#define FILE 1

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

int T, boo;
long long p, q, k;

long long gcd (long long p, long long q)
{
	if (q == 0)
		return p;
	return gcd(q, p % q);
}

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &T);
	for (int g = 0; g < T; g++)
	{
		scanf("%I64d/%I64d", &p, &q);
		printf("Case #%d: ", g + 1);
		k = gcd(p, q);
		p /= k;
		q /= k;
		boo = 0;
		for (int i = 0; i <= 40; i++)
			if ((1ll << i) == q)
		    	boo = 1;
		if (!boo)
		{
			puts("impossible");
			continue;
		}
		for (int i = 1; i <= 40; i++)
			if (p * (1ll << i) >= q)
			{
				printf("%d\n", i);
				break;
		   	}
	}
	return 0;
}