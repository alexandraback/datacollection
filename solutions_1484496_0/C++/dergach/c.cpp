#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

int T, t, N, a[505], j, i, k, b[2000005], sum;

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	cin >> T;
	for(t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		memset(b, 0, sizeof(b));
		for(i = 0; i < N; i++)
			scanf("%d", &a[i]);

		printf("Case #%d:\n", t);

		for(i = 1; i < (1 << N); i++)
		{
			sum = 0;
			for(j = 0; j < N; j++)
				if(i & (1 << j))
					sum += a[j];
			if(b[sum] != 0)
			{
				vector <int> v;
				for(j = 0; j < N; j++)
					if(i & (1 << j))
						v.push_back(a[j]);
				for(j = 0; j < v.size(); j++)
				{
					if(j) printf(" ");
					printf("%d", v[j]);
				}
				puts("");
				v.clear();
				for(j = 0; j < N; j++)
					if(b[sum] & (1 << j))
						v.push_back(a[j]);
				for(j = 0; j < v.size(); j++)
				{
					if(j) printf(" ");
					printf("%d", v[j]);
				}
				puts("");
				break;
			}
			b[sum] = i;
		}
		if(i == (1 << N))
			printf("Impossible\n");
	}
	return 0;
}