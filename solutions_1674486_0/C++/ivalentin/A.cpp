#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;


#define ASSERT(X) {if (!(X)) {printf("\n assertion failed at line %d\n",__LINE__);exit(0);}}

/*
inline int bestScoreWithoutSurprise(int total)
{
	return (total + 2) / 3;
}

inline int bestScoreWithSurprise(int total)
{
	return (total + 4) / 3;
}
*/

int p[1000][10];
int nm[1000];
int go[1000];

void travel(int node)
{
	//printf("Travel %d\n", node+1);
	for (int j = 0; j < nm[node]; j++)
	{
		go[p[node][j]]++;
		if (go[p[node][j]] > 1)
		{
			break;
		}
		travel(p[node][j]);
	}
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1;case_id<=testcase;case_id++)
	{
		int res = 0;
		printf("Case #%d: ",case_id);
		
		int n = 0;
		scanf("%d",&n);

		for (int i = 0; i < n; i++)
		{
			int m;
			scanf("%d", &m);

			nm[i] = m;

			for (int j = 0; j < m; j++)
			{
				scanf("%d", &p[i][j]);
				p[i][j]--;
			}
		}

		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				go[j] = 0;
			}
			travel(i);
			for (int j = 0; j < n; j++)
			{
				if (go[j] > 1)
				{
					res = 1;
					goto endtest;
				}
			}
		}

endtest:
		if (res == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}

		//printf("%.6f\n", res);
		fflush(stdout);
	}
	return 0;
}

