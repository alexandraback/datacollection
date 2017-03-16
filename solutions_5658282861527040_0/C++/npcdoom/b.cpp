#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; t += 1)
	{
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		
		long long total = 0;
		for (int i = 0; i < a; i += 1)
		{
			for (int j = 0; j < b; j += 1)
			{
				if ((i & j) < k)
					++total;
			}
		}
		
		printf("Case #%d: %lld\n",t,total);
	}
	return 0;
}
