#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

int T;
long long r, t;

long long getResult()
{
	scanf("%lld %lld", &r, &t);
	int n = 1;

	while(2*r + 4*n - 3 <= t)
	{
		t -= 2*r + 4*n - 3;
		n++;
	}

	return n-1;
}

int main()
{
	scanf("%d", &T);
	
	for(int ca = 1; ca <= T; ca++)
	{
		printf("Case #%d: %lld\n", ca, getResult());
	}

	return 0;
}

