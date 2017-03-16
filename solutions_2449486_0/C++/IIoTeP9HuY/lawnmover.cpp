#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>

using namespace std;

const char* inputFile = "B-small-attempt0.in";
const char* outputFile = "B-small-attempt0.out";

string solveTest()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int height[n][m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &height[i][j]);
		}
	}

	bool cutted[n][m];
	memset(cutted, 0, sizeof(cutted));
	for (int i = 0; i < n; ++i)
	{
		int maxHeight = height[i][0];
		for (int j = 0; j < m; ++j)
		{
			maxHeight = max(maxHeight, height[i][j]);
		}
		for (int j = 0; j < m; ++j)
		{
			if (maxHeight == height[i][j])
			{
				cutted[i][j] = true;
			}
		}
	}
	for (int j = 0; j < m; ++j)
	{
		int maxHeight = height[0][j];
		for (int i = 0; i < n; ++i)
		{
			maxHeight = max(maxHeight, height[i][j]);
		}
		for (int i = 0; i < n; ++i)
		{
			if (maxHeight == height[i][j])
			{
				cutted[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!cutted[i][j])
			{
				return "NO";
			}
		}
	}
	return "YES";
}

int main()
{
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	size_t T;
	scanf("%d\n", &T);
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		string verdict = solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
