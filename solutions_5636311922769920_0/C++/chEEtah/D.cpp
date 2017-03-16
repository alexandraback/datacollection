#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d:", tt);
		
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);

		if (C * S < K)
		{
			puts(" IMPOSSIBLE");
			continue;
		}

		int i = 0;
		while(i < K)
		{
			long long int cur = 0;
			for(int j = 0; j < C; j++)
			{
				if (i == K) break;
				cur = cur * K + i;
				i++;
			}
			cout << " " << cur + 1;
		}
		puts("");
	}
	return 0;
}