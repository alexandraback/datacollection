#include<iostream>
#include<vector>

#define MAX 1000

bool color[MAX];
bool nvr_begin[MAX];

bool rec(int point, std::vector<int> *g)
{
	if(color[point]) return true;
	color[point] = true;
	for(int i = 0; i < g[point].size(); i++)
		if(rec(g[point][i],g))
			return true;
	return false;
}

int main()
{
	int T; std::cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		std::vector<int> graf[MAX];
		int N; std::cin >> N;
		for(int i = 0; i < N; i++)
			nvr_begin[i] = 1;
		for(int i = 0; i < N; i++)
		{
			int M; std::cin >> M;
			for(int j = 0; j < M; j++)
			{
				int X; std::cin >> X;
				X--;
				graf[i].push_back(X);
				nvr_begin[X] = 0; 
			}
		}
		bool success = 0;
		for(int i = 0; i < N; i++)
			if(nvr_begin[i])
			{
				for(int j = 0; j < N; j++)
					color[j] = 0;
				if(rec(i,graf))
				{
					success = 1;
					break;
				}
			}

		std::cout << "Case #" << ii+1 << ": " << (success?"Yes":"No") << '\n';
	}
	return 0;
}
