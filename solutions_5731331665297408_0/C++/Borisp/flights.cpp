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

vector<vector<int> > neighbours;
bool contains(const vector<int>& v, int val)
{
	for (int i = 0; i < v.size(); i++)
	{
		if(v[i] == val)
			return true;
	}
	return false;
}
bool does(const vector<int>& permutation)
{

	vector<int> visited;
	visited.push_back(permutation[0]);
	for (int i = 1; i < permutation.size(); i++)
	{
		while(visited.size() > 0)
		{
			if (contains(neighbours[visited.back()], permutation[i]))
			{
				visited.push_back(permutation[i]);
				break;
			}
			else
			{
				visited.pop_back();
			}
		}
		if(visited.size() == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("google.in", "r", stdin);
	freopen("google.out", "w", stdout);
	int numTests;
	cin >> numTests;
	for(int testCounter = 0; testCounter < numTests; ++testCounter)
	{
		printf("Case #%d: ", testCounter + 1);
		int n, m;
		cin >> n >> m;
		vector<string> labels(n);
		for (int i = 0; i < n; i++)
		{
			cin >> labels[i];
		}
		neighbours.clear();
		neighbours.resize(n);
		int x, y;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			neighbours[x].push_back(y);
			neighbours[y].push_back(x);
		}

		vector<int> permutation(n);
		for (int i = 0; i < n; i++)
		{
			permutation[i] = i;
		}
		string best = "";
		do {
			if (does(permutation))
			{
				string combinedLabel = "";
				for (int i = 0; i < n; i++)
					combinedLabel += labels[permutation[i]];
				if (best == "" || best > combinedLabel) {
					best = combinedLabel;
				}

			}
		} while(next_permutation(permutation.begin(), permutation.end()));
		cout << best << endl;

	}
	return 0;
}
