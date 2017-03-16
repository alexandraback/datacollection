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

typedef struct
{
	int dist;
	int length;
} vine;

vine v[10000];
int d;
int pos;
int n;
typedef pair<int, int> State;
map<State, int> dp;

int travel(int cpos, int cv)
{
	State s = make_pair(cpos,cv);
	if (dp.find(s) != dp.end())
	{
		return 0;
	}
}
*/

char* str[100];
int strl[100];
int comp[100][100];

int nbGenerations(int n, int d, int max)
{
	int found = 0;
	int res = 0;

	while ((found == 0) && (res < max))
	{
		if ((2 * n - d) % 2 != 0)
		{
			n = n * 2;
			d = d * 2;
		}
		//printf("%d/%d\n", n, d);
		if (((2 * n - d) >= 0))
		{
			res++;
			//Calculer la part de l'autre pour s'assurer que c'est possible
			if ((2 * n - d) != 0)
			{
				int a = nbGenerations((2 * n - d), d, (max - res));
				if (a == -1)
				{
					return -1;
				}
			}
			found = 1;
		}
		else
		{
			res++;
			n = n * 2;
		}
	}

	if (found == 0)
	{
		return -1;
	}

	return res;
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);

	//int u = nbGenerations(18, 46, 40);

	int testcase;
	scanf("%d",&testcase);
	for (int case_id=1; case_id<=testcase; case_id++)
	{
		int n;
		int d;
		int res = 0;

		printf("Case #%d: ",case_id);

		scanf("%d/%d", &n, &d);

		res = nbGenerations(n, d, 40);

		if (res >= 0 && res <= 40)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("impossible\n");
		}
		fflush(stdout);
	}
	return 0;
}

