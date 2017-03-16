/*
 * diamond.cpp
 *
 *  Created on: May 6, 2012
 *      Author: firat
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class graph
{
public:
	graph(int N_)
	{
		N = N_;
		neighbors = new vector<int>[N];
		visited = new vector<int>[N];
	}
	~graph()
	{
		delete[] neighbors;
		delete[] visited;
	}
	void clear_visited()
	{
		for(int i = 0; i < N; i++)
		{
			visited[i].clear();
		}
	}
	vector<int>* neighbors;
	vector<int>* visited;
	int N;
};

bool visit(const graph& G, int root, int parent)
{
	//cout << "Visit " <<root<<endl;

	if(parent != -1)
	{
		G.visited[root].push_back(parent);
		G.visited[root].insert(G.visited[root].end(), G.visited[parent].begin(), G.visited[parent].end());
		/*for(int i = 0; i < G.visited[parent].size(); i++)
		{
			G.visited[root].push_back(G.visited[parent][i]);
		}*/
		sort(G.visited[root].begin(), G.visited[root].end());
		for(int i = 0; i < G.visited[root].size()-1; i++)
		{
			if(G.visited[root][i] == G.visited[root][i+1])
			{
				return true;
			}
		}
	}
	for(int i = 0; i < G.neighbors[root].size(); i++)
	{
		//cout << "Root: " << root << endl;
		bool result = visit(G, G.neighbors[root][i], root);

		if(result)
		{
			return true;
		}
	}
	return false;

}

int main()
{
	int T;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		graph G(N);
		for(int j = 0; j < N; j++)
		{
			int K;
			cin >> K;
			for(int k = 0; k < K; k++)
			{
				int neig;
				cin >> neig;
				G.neighbors[j].push_back(neig-1);
			}
		}
		bool yes = false;
		for(int j = 0; j < N; j++)
		{
			G.clear_visited();
			if(N > 2 && G.visited[j].size() == 0 && visit(G, j, -1))
			{
				cout << "Case #" << i+1 << ": Yes" <<endl;
				yes = true;
				break;
			}
		}

		if(!yes)
		{
			cout << "Case #" << i+1 << ": No" <<endl;
		}

	}
}




