// ZADANIE_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

///
#include <stdio.h>
#include <vector>
#include <hash_map>
#include <deque>
#include <set>

using namespace std;

class Graph {
	public:
		int n;
		vector< vector<int> > adj;
		
		Graph(int vertices) : n(vertices)
		{
			adj.resize(n+1);
		}

		void addEdge(int i, int j) {
			adj[i].push_back(j);
		}

		bool diamond (int i){
			set<int> visited;
			deque<int> q;

			//visited.insert(i);
			q.push_back(i);

			while ( !q.empty() )
			{
				int curr = q.front();
				q.pop_front();
				if (visited.find(curr) !=visited.end() )
					return true;

				visited.insert(curr);
				
				for (int i=0; i<adj[curr].size(); ++i)
				{
					int neighbour = adj[curr].at(i);
					//visited.insert(neighbour);

					//for (int j=0; j< adj[neighbour].size(); ++j)
					//	q.push_back( adj[neighbour].at(j));
					q.push_back(neighbour);
				};

				//--phases;
			}

			return false;
		}


};

int main(int argc, char* argv[])
{
	//freopen("c://temp//A-small-attempt0.in", "r+", stdin);
	freopen("c://temp//in.txt", "r+", stdin);
	freopen("c://temp//out.txt", "w+", stdout);

	int cases;
	scanf("%i", &cases);

	for (int i=1;i<=cases; ++i)
	{
		int N, M, curr;
		scanf("%i", &N);
		Graph* G = new Graph(N);

		for (int j=1; j<=N; ++j)
		{
			scanf("%i", &M);

			for (int k=1; k<=M; ++k)
			{
				scanf("%i", &curr);
				G->addEdge(j, curr);
			};

		};

		bool result = false;
		for (int o=1;o<=N; ++o)
		{
			if (G->diamond(o))
			{
				result = true;
				break;
			};
		}

		printf("Case #%i: %s\n", i, ( result == true ? "Yes" : "No" ) );
		delete G;
	};

	return 0;
}

