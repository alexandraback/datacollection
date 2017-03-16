#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

std::vector<std::set<int> > graph;
struct node
{
	std::string str;
	int id;
} cities[50];

bool comp(node a, node b)
{
	return a.str < b.str;
}

int main()
{
	std::ios::sync_with_stdio(0);
	int T; std::cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		int N, M; std::cin >> N >> M;
		graph.clear();
		graph.resize(N);
		for(int i = 0; i < N; i++)
		{
			std::cin >> cities[i].str;
			cities[i].id = i;
		}
		for(int i = 0; i < M; i++)
		{
			int a, b; std::cin >> a >> b;
			a--; b--;
			graph[a].insert(b);
			graph[b].insert(a);
		}
		std::sort(cities, cities+N, comp);
		int que[20], q_size;
		do
		{
			que[0] = cities[0].id;
			q_size = 1;
			for(int i = 1; i < N; i++)
			{
				#define EXPR graph[que[q_size-1]]
				while(q_size && EXPR.find(cities[i].id) == EXPR.end())
					q_size--;
				#undef EXPR
				if(!q_size) break;
				que[q_size++] = cities[i].id;
			}
			if(!q_size) continue;
			else break;
		} while(std::next_permutation(cities, cities+N, comp));
		std::cout << "Case #" << ii+1 << ": ";
		for(int i = 0; i < N; i++)
			std::cout << cities[i].str;
		std::cout << "\n";
	}
	return 0;
}
