#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

void updateFlags(vector<bool> &flags, int V, int C, int coin)
{
	for (int i = V; i >= 1; --i)
	{
		if (true == flags[i])
		{
			for (int j = 1; j <= C; ++j)
			{
				if (i + j * coin <= V)
				{
					flags[i + j * coin] = true;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int i = 1; i <= C; ++i)
	{
		if (i * coin <= V)
		{
			flags[i * coin] = true;
		}
		else
		{
			break;
		}
	}
}

int solve(int C, int D, int V, vector<int> &curCoins)
{
	int ans = 0;
	vector<bool> flags(V+1, false);
	for (int i = 0; i < curCoins.size(); ++i)
	{
		updateFlags(flags, V, C, curCoins[i]);
	}
	for (;;)
	{
		int coin = 0;
		for (int i = 1; i <= V; ++i)
		{
			if (false == flags[i])
			{
				coin = i;
				break;
			}
		}
		if (0 != coin)
		{
			++ans;
			updateFlags(flags, V, C, coin);
		}
		else
		{
			break;
		}
	}
	return ans;
}

int main()
{
	FILE * infile = fopen("C-small-attempt0.in", "r");
	FILE * outfile = fopen("out.txt", "w");

	int T;
	fscanf(infile, "%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		int C, D, V;
		fscanf(infile, "%d %d %d", &C, &D, &V);
		vector<int> curCoins;
		for (int j = 0; j < D; ++j)
		{
			int t;
			fscanf(infile, "%d", &t);
			curCoins.push_back(t);
		}
		int ans = solve(C, D, V, curCoins);
		fprintf(outfile, "Case #%d: %d\n", i, ans);
	}

	fclose(infile);
	fclose(outfile);
	return 0;
}

