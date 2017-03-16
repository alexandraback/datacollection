#include "stdafx.h"
#include "stdafx.h"
#include "fstream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "sstream"
#include "string"
#include "algorithm"
#include "unordered_map"
#include "unordered_set"
#include "cassert"

using namespace std;
using namespace tr1;



#define int long long



void rec(int v, vector<vector<int>>& graph, vector<int>& colors, bool& isDiamond)
{
	if (isDiamond)
	{
		return;
	}
	for (int i = 0; i < graph[v].size(); ++i)
	{
		if (colors[graph[v][i]] == 1)
		{
			isDiamond = true;
			break;
		}
		colors[graph[v][i]] = 1;
		rec(graph[v][i], graph, colors, isDiamond);
	}
}

int Run(fstream& f, bool& isDiamond)
{

	vector<vector<int>> graph;


	int n;
	f >> n;
	graph.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int l;
		f >> l;
		graph[i].resize(l);
		for (int j = 0; j < l; ++j)
		{
			int v;
			f >> v;
			graph[i][j] = v - 1;
		}
	}

	

	for (int i = 0; i < n; ++i)
	{
		vector<int> colors(n, 0);
		//if (colors[i] == 0)
		//{
			rec(i, graph, colors, isDiamond);
		//}
	}






  return 0;

}

void main()
{

	

	fstream f("a.in");
	fstream r("result.txt");
	int t;
	f >> t;

	for (int j = 0; j < t; ++j)
	{
		bool isDiamond = false;
		auto result = Run(f, isDiamond);			
		r << "Case #" << j + 1 << ": " << (isDiamond ? "Yes": "No") << endl;		
	}

	r.close();
	f.close();
}
