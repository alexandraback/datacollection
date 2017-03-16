#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
long long P,Q;

long long gcd(long long a, long long b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}
bool is2(long long a, int& cnt)
{
	long long k = 1;
	while((a&k)==0)
	{
		cnt++;
		a>>=1;
	}
	return (a==k);
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%lld/%lld",&P, &Q);
		printf("Case #%d: ",i);
		long long g = gcd(P,Q);
		P = P/g;
		Q = Q/g;
		int cnt = 0;
		bool right = is2(Q,cnt);
		if (!right)
			printf("impossible\n");
		else
		{
			int j=0;
			for (j=0;j<cnt;j++)
				if (P>=Q)
					break;
				else
					Q>>=1;
			printf("%d\n", j);
		}
		
	}
	return 0;
}