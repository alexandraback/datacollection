#include <set>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool bfs(vector< set<int> > &graph, int vertex = 0, ostream &stream = cout)
{
	// Verificar que el vertice inicial este en el grafo
	if (vertex >= graph.size())
	{
		//cout << "Vertex " << vertex << " not in graph" << endl;
		return false;
	}

	// Vector donde indicamos vertices ya visitados, inicialmente no hay ninguno visitado (false)
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(vertex); // Se comienza por el vertice indicado

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		// Se visita el primer vertice de la cola
		visited[v] = true;
		//stream << v << " ";

		// Se recorre la lista de adyacencia de dicho vertice
		for (set<int>::iterator it = graph[v].begin();
				it != graph[v].end(); ++ it)
		{
			if (!visited[*it])
			{
				// Si no fue visitado...
				q.push(*it); // Encolarlo
				visited[*it] = true; // Marcarlo para no volverlo a visitar
			}
			else if (*it != vertex)
				return true;
		}
	}
	//stream << endl;
	return false;
}

int main(int argc, const char *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i ++)
	{
		int N;
		cin >> N;
		vector< set<int> > G(N);
		for (int j = 0; j < N; j ++)
		{
			int M;
			cin >> M;
			for (int k = 0; k < M; k ++)
			{
				int a;
				cin >> a;
				G[j].insert(a-1);
			}
		}
		//bool R = bfs(G, 0, cout);
		bool R = false;
		for (int j = 0; j < N; j ++)
		{
			R = bfs(G, j, cout);
			if (R) break;
		}
		cout << "Case #" << i+1 << ": " << (R?"Yes":"No") << endl;
	}
	return 0;
}
