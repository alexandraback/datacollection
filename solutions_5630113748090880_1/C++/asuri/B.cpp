#include <vector>
using namespace std;
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <unordered_set>
#include <algorithm>

vector<int> find_missing(int N, vector<vector<int>> &nums)
{
	unordered_map<int, int> m;
	for(int i=0; i<2*N-1; i++)
	{
		for (int j=0; j<N; j++)
		{
			m[nums[i][j]]++;
		}
	}
	vector<int> res;
	for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if(it->second % 2 != 0)
			res.push_back(it->first);
	}
	sort(res.begin(), res.end());
	return res;
}

void main()
{
	ifstream ifile("B-large.in");
	ofstream ofile("B-large.out");
	int n_tests;
	ifile >> n_tests;
	for (int id=0; id<n_tests; id++)
	{
		int N;
		ifile >> N;
		vector<vector<int>> nums(2*N-1, vector<int>(N, 0));
		for(int i=0; i<2*N-1; i++)
		{
			for (int j=0; j<N; j++)
			{
				ifile >> nums[i][j];
			}
		}
		vector<int> res = find_missing(N, nums);
		ofile << "Case #" << id+1 << ":";
		for (int i=0; i<N; i++)
		{
			ofile << ' ' << res[i];
		}
		ofile << endl;
	}
	ofile.close();
}

