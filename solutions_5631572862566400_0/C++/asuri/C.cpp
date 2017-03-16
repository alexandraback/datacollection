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
#include <set>

int longest_side(vector<set<int>> &from_edges, int i, int j)
{
	set<int> test = from_edges[i];
	test.erase(j);
	if(from_edges[i].empty() || test.empty())
		return 0;

	int res = 0;
	for (set<int>::iterator it = from_edges[i].begin(); it !=from_edges[i].end(); it++)
	{
		if(*it == j)
			continue;
		res = max(res, longest_side(from_edges, *it, -1));
	}
	return res+1;
}

int longest_circle(vector<int> &to_edges, int i)
{
	unordered_set<int> s;
	int cur = to_edges[i];
	int res = 1;
	while(cur != i)
	{
		if(s.find(cur) != s.end())
			return 0;
		else
		{
			s.insert(cur);
			cur = to_edges[cur];
			res++;
		}
	}
	return res;
}

int BBF(vector<int> &to_edges)
{
	vector<set<int>> from_edges(to_edges.size());
	for (int i=0; i<to_edges.size(); i++)
	{
		from_edges[to_edges[i]].insert(i);
	}

	int circle_max = 0;
	int circle_len2_count = 0;
	int circle_side_max = 0;
	for (int i=0; i<to_edges.size(); i++)
	{
		int circle_len = longest_circle(to_edges, i);
		circle_max = max(circle_max, circle_len);

		if(circle_len == 2)
		{
			circle_len2_count++;
			circle_max = max(circle_max, 2+longest_side(from_edges, to_edges[i], i)+ longest_side(from_edges, i, to_edges[i]));
		}
	}
	circle_len2_count /= 2;
	return circle_len2_count>2? max(circle_max, 4) : circle_max;
}

void main()
{
	//vector<int> test;
	//test.push_back(2);
	//test.push_back(2);
	//test.push_back(3);
	//test.push_back(2);
	//cout << BBF(test) << endl;
	//getchar();
	//getchar();
	ifstream ifile("C-small-attempt3.in");
	ofstream ofile("C-small-attempt3.out");
	int n_tests;
	ifile >> n_tests;
	for (int id=0; id<n_tests; id++)
	{
		int N;
		ifile >> N;
		vector<int> to_edges(N);
		for (int i=0; i<N; i++)
		{
			ifile >> to_edges[i];
			to_edges[i]--;
		}
		ofile << "Case #" << id+1 << ": " << BBF(to_edges) << endl;;
	}
	ofile.close();
}

