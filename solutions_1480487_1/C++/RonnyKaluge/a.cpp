#include <iostream>
#include <stack>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define A first
#define B second
#define EPS 0.000000000001

int main()
{
	int i, j, k, T, N, total;
	int point[200];
	double aw, ak, t, res, P, vote, temp;
	cin >> T;
	for (int t_=1; t_<=T; ++t_)
	{
		scanf("%d",&N);
		total = 0;
		for (i=0; i<N; ++i)
		{
			scanf("%d",&point[i]);
			total+=point[i];
		}
		printf("Case #%d:", t_);
		for (i=0; i<N; ++i)
		{
			aw = 0;
			ak = 1;
			while (ak-aw > EPS)
			{
				vote = t = (aw+ak)/2;
				P = point[i]+t*total;
				k = 0;
				for (j=0; j<N; ++j)
					if (i!=j)
					{
						if (P > point[j])
						{
							temp = (P-point[j])/total;
							if (vote+temp <= 1)
							{
								++k;
								vote += temp;
							}
							else
							{
								vote = 2;
								break;
							}
						}
					}
				if (vote > 1)
					ak = t;
				else if (1-vote>EPS)
				{
					aw = t;
				}
				else
				{
					aw = ak = t;
				}
			}
			printf(" %lf", t*100.0);
		}
		printf("\n");
	}
	return 0;
}
