#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <set>
using namespace std;
string solve(vector<vector<int>> &path,vector<vector<int>> &path2);
int main()
{
	std::ifstream f("A-small-attempt1.in");
	std::ofstream o("result1-1.txt");

	int size;
	f >> size;
	
	for(int i = 0; i < size; i++)
	{
		int n;
		f >> n;
		vector<vector<int>> path(n);
		vector<vector<int>> path2(n);
		for(int j = 0; j < n; j++)
		{
			int m;
			f >> m;
			for(int k = 0; k < m; k++)
			{
				int t;
				f >> t;
				path[t-1].push_back(j);
				path2[j].push_back(t-1);
			}
		}

		string result = solve(path,path2);

		std::cout << "Case #" << i+1 << ": " << result << std::endl;	
		o << "Case #" << i+1 << ": " << result << std::endl;
	}
	return 0;
}

string solve(vector<vector<int>> &path,vector<vector<int>> &path2)
{
	vector<int> pos;
	for(int i = 0; i < (int)path2.size(); i++)
	{
		if(path2[i].size() == 0)
			pos.push_back(i);
	}

	for(int i = 0; i < (int)pos.size(); i++)
	{
		vector<int> forward;
		queue<int> bfs;
		bfs.push(pos[i]);
		int cnt = 0;
		set<int> tt;		
		while(bfs.size() != 0)
		{
			
			if(tt.find(bfs.front()) == tt.end())
				tt.insert(bfs.front());
			else
				return "Yes";
			forward = path[bfs.front()];
			bfs.pop();		
			for(int i = 0; i < (int)forward.size(); i++)
			{
				bfs.push(forward[i]);
			}
		}			
	}
	return "No";
}