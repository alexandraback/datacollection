#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;


int main()
{
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);

	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);

	int inp, kase, i, j, k, a, b;
	scanf("%d", &inp);
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d %d %d", &a, &b, &k);
		int cnt = 0;
		for(i = 0; i < a; i++)
		{
			for(j = 0; j < b; j++)
			{
				int c = (i & j);
				if(c < k)
					cnt++;
			}
		}
		printf("Case #%d: %d\n", kase, cnt);
		
	}

	return 0;
}
