
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <tuple>

using namespace std;


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

double farm(int nbFarm, double c, double f, double lastAnswer)
{
	if (nbFarm <= 0)
	{
		return 0;
	}
	else
	{
		return (c / (2.0 + ((nbFarm - 1) * f))) + lastAnswer;
	}
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		int a, b, k;
		int res = 0;

		printf("Case #%d: ",case_id);
		scanf("%d %d %d",&a,&b,&k);
		
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if ((i & j) < k)
				{
					//printf("%d %d\n", i, j);
					res++;	
				}
			}
		}

		printf("%d\n", res);

		fflush(stdout);
	}
	return 0;
}