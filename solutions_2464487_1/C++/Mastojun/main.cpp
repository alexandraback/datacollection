#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

#include "BigIntegerLibrary.hh"
using namespace std;

int T;
long long r, t;

long long getResult()
{
	scanf("%lld %lld", &r, &t);
	long long b = 2*r - 1;
	long long c = -t;

	return (-b/4.0 + sqrt(b/4.0*b/4.0 - c/2));
}

int main()
{
	scanf("%d", &T);
	
	for(int ca = 1; ca <= T; ca++)
	{
		long long result = getResult();
		long long actualResult = result-10000;
		for(;; actualResult++)
		{
			if(actualResult < 0) continue;
			if(2*actualResult*actualResult
				- actualResult + 2*r*actualResult > t){
					break;
			}
		}
		printf("Case #%d: %lld\n", ca, actualResult-1);
	}

	return 0;
}

