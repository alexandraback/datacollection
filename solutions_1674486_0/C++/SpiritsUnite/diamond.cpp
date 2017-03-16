#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ifstream in("diamond.in");
	ofstream out("diamond.out");
	int T;
	in >> T;
	for (int c = 1; c <= T; c++)
	{
		int n;
		in >> n;
		vector<int> adjList[1020];
		for (int i = 0; i < n; i++)
		{
			int m;
			in >> m;
			for (int j = 0; j < m; j++)
			{
				int a;
				in >> a;
				a--;
				adjList[i].push_back(a);
			}
		}
		bool good = false;
		for (int i = 0; i < n; i++)
		{
			bool seen[1020] = {false};
			seen[i] = true;
			queue<int> q;
			q.push(i);
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				for (int j = 0; j < adjList[node].size(); j++)
				{
					int next = adjList[node][j];
					if (seen[next])
					{
						good = true;
						break;
					}
					else
					{
						seen[next] = true;
						q.push(next);
					}
				}
				if (good)
					break;
			}
		}
		out << "Case #" << c << ": ";
		if (good)
			out << "Yes";
		else
			out << "No";
		out << '\n';
	}
	return 0;
}

