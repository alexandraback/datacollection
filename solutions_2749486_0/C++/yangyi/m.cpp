#include <string>
#include <cctype>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <memory.h>
#include <assert.h>
using namespace std;

void Calculate();
int x,y;
char direction[4]={'E', 'S', 'W', 'S'};

int main(void)
{
	freopen("a.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int nTest;
	scanf("%d", &nTest);

	for (int i = 0; i < nTest ; i++)
	{
		printf("Case #%d: ",i+1);
		scanf("%d %d", &x, &y);
		Calculate();
	}
}

void Calculate()
{
	if (x > 0)
	{
		for (int i = 0; i < x ; i++)
		{
			printf("WE");
		}
	}
	else if (x < 0)
	{
		x = x*(-1);
		for (int i = 0; i < x ; i++)
		{
			printf("EW");
		}
	}
	if (y > 0)
	{
		for (int i = 0; i < y ; i++)
		{
			printf("SN");
		}
	}
	else if (y < 0)
	{
				y = y*(-1);
		for (int i = 0; i < y ; i++)
		{
			printf("NS");
		}
	}

	printf("\n");
}
