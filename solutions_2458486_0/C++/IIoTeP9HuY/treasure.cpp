#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "D-small-attempt0.in";
const char* outputFile = "D-small-attempt0.out";

class Solver
{
public:
	string solveTest()
	{
		scanf("%d%d", &startKeysNumber, &chestsNumber);

		int keysBalance[40];
		memset(keysBalance, 0, sizeof(keysBalance));
		for (int i = 0; i < startKeysNumber; ++i)
		{
			int keyNumber;
			scanf("%d", &keyNumber);
			++keysBalance[keyNumber];
		}
		openKeysTypes.assign(chestsNumber, 0);
		keysInside.assign(chestsNumber, vector<int>());
		for (int i = 0; i < chestsNumber; ++i)
		{
			scanf("%d", &openKeysTypes[i]);
			int keysInsideNumber;
			scanf("%d", &keysInsideNumber);
			for (int j = 0; j < keysInsideNumber; ++j)
			{
				int keyInside;
				scanf("%d", &keyInside);
				keysInside[i].push_back(keyInside);
			}
		}

		bool visited[1 << chestsNumber];
		memset(visited, 0, sizeof(visited));

		int path[chestsNumber];
		memset(path, 0, sizeof(chestsNumber));
		if (canOpenChests(0, visited, keysBalance, path, 0))
		{
			string pathString;
			for (int i = 0; i < chestsNumber; ++i)
			{
				pathString = pathString + to_string(path[i] + 1) + " ";
			}
			return pathString;
		}
		else
		{
			return "IMPOSSIBLE";
		}
	}

private:
	bool canOpenChests(int mask, bool visited[], int keysBalance[], int path[], size_t chestsOpened)
	{
		visited[mask] = true;
		if (chestsOpened == chestsNumber)
		{
			return true;
		}
		for (int i = 0; i < chestsNumber; ++i)
		{
			if (((mask & (1 << i)) == 0) && keysBalance[openKeysTypes[i]] > 0)
			{
				int newMask = mask | (1 << i);
				if (visited[newMask])
					continue;

				--keysBalance[openKeysTypes[i]];
				for (int j = 0; j < keysInside[i].size(); ++j)
				{
					int keyInside = keysInside[i][j];
					keysBalance[keyInside]++;
				}

				path[chestsOpened] = i;
				if (canOpenChests(newMask, visited, keysBalance, path, chestsOpened + 1))
				{
					return true;
				}

				for (int j = 0; j < keysInside[i].size(); ++j)
				{
					int keyInside = keysInside[i][j];
					keysBalance[keyInside]--;
				}
				++keysBalance[openKeysTypes[i]];
			}
		}
		return false;
	}


	int startKeysNumber, chestsNumber; 
	vector<int> openKeysTypes;
	vector<vector<int>> keysInside;
};

int main()
{
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	Solver solver;
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		DB(testNumber);
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
