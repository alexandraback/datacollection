#pragma warning(disable: 4996)
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


int Calculate(int r, int c, int w)
{
	int numOfShip = c / w;
	int rem = c%w;
	if (rem == 0)
	{
		return r*numOfShip + w - 1;
	}
	else
	{
		return r*numOfShip + w;
	}
}


int main(void)
{
//	freopen("A-small-attempt0 (1).in", "r", stdin);
 	freopen("A-large (1).in", "r", stdin);
// 	freopen("1.txt", "r", stdin);
	freopen("Alarge.out", "w", stdout);
	int nTest;

	scanf("%d", &nTest);
	for (int i = 0; i < nTest; i++)
	{
		int r, c, w;
		scanf("%d %d %d", &r, &c, &w);
		cout << "Case #" << i + 1 << ": " << Calculate(r, c, w) << endl;

	}

	return 1;
}