/*
 * main.cpp
 *
 *  Created on: 2015-5-10
 *      Author: wufangyu
 */
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")
const int MAXN = 10;
char keyboards[MAXN];
char target[MAXN];
int K, L, S;
int maxb, casenum, bnanum;
char data[MAXN];

void dfs(int step)
{
	if (step == S)
	{
		casenum++;
		int b = 0;
		for (int off = 0; off <= S - L; off++)
		{
			int i = 0;
			for (; i < L; i++)
			{
				if (target[i] != data[off + i])
				{
					break;
				}
			}
			if (i == L)
			{
				b++;
			}
		}
		bnanum += b;
		if (b > maxb)
		{
			maxb = b;
		}
		return ;
	}
	for (int k = 0; k < K; k++)
	{
		data[step] = keyboards[k];
		dfs(step + 1);
	}
}

int main()
{
	int T;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d%d%d", &K, &L, &S);
		scanf(" %s %s", keyboards, target);
		casenum = bnanum = maxb = 0;
		dfs(0);
		printf("Case #%d: %.7lf\n", t, maxb - (bnanum + 0.0) / casenum);
	}
	return 0;
}

