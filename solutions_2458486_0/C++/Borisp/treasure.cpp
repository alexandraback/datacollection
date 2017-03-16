#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<numeric>
#include<math.h>
#include<set>
#include<map>
#include<fstream>
#define epsilon 0.000000001
#define cosinusa(a, b, c) ((a * a + b * b - c * c) / (2.0 * a * b));
#define infi 1000000000
using namespace std;
struct chest
{
	int unlock;
	vector<int> contains;
};

bool can[1 << 20];
int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d:", testCounter + 1);
		int n, k;
		cin >> k >> n;
		vector<int> startingKeys(k);
		for (int i = 0; i < k; i++)
			cin >> startingKeys[i];
		vector<chest> chests(n);
		int x, y;
		for (int i = 0; i < n; i++)
		{
			cin >> chests[i].unlock;
			cin >> x;
			for (int j = 0; j < x; j++)
			{
				cin >> y;
				chests[i].contains.push_back(y);
			}
		}
		can[0] = true;
		for (int i = 1; i < (1 << n); i++)
		{
			map<int, int> keys;
			for (int j = 0; j < startingKeys.size(); j++)
			{
				keys[startingKeys[j]]++;
			}
			for (int j = 0; j < n; j++)
			{
				if (!(i & (1 << j)))
				{
					keys[chests[j].unlock]--;
					for (int p = 0; p < chests[j].contains.size(); p++)
					{
						keys[chests[j].contains[p]]++;
					}
				}
			}
			can[i] = false;
			for (int j = 0; j < n; j++)
			{
				if ((i & (1 << j)) && keys[chests[j].unlock] > 0 && can[i ^ (1 << j)]) 
				{
					can[i] = true;
					break;
				}
			}
		}
		int mask = (1 << n) - 1;
		if (!can[(1 << n) - 1])
		{
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		vector<int> solution;
		for(int i = 0; i < n; i++)
		{
			map<int, int> keys;
			for (int j = 0; j < startingKeys.size(); j++)
			{
				keys[startingKeys[j]]++;
			}
			for (int j = 0; j < n; j++)
			{
				if (!(mask & (1 << j)))
				{
					keys[chests[j].unlock]--;
					for (int p = 0; p < chests[j].contains.size(); p++)
					{
						keys[chests[j].contains[p]]++;
					}
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (!(mask & (1 << j)))
					continue;
				if (keys[chests[j].unlock] > 0 && can[mask ^ (1 << j)])
				{
					mask ^= (1 << j);
					solution.push_back(j);
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << " " << solution[i] + 1;
		cout << endl;
	}
	return 0;
}
