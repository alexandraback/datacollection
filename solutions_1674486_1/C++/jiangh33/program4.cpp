#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <fstream>
using namespace std;

const int N = 1005, M = 11;
int g[N][M], vis[N], anse[N];
int n;

bool dfs(int cur)
{
	if(vis[cur]) return 1;
	vis[cur] = 1;
	for(int i = 0; i < g[cur][0]; ++ i)
		if(dfs(g[cur][i+1]))
			return 1;
	return 0;
}

int main()
{
	fstream in("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\data.txt");
	fstream out("C:\\Users\\Administrator\\Documents\\Visual Studio 2010\\Projects\\program4\\program4\\ans.txt");

	int ntest;
	in>>ntest;
	for(int itest = 1; itest <= ntest; ++ itest)
	{
		memset(g, 0, sizeof(g));
		memset(anse, 0, sizeof(anse));
		in>>n;
		for(int i = 0; i < n; ++ i)
		{
			in>>g[i][0];
			for(int j = 0; j < g[i][0]; ++ j)
			{
				int p;
				in>>p;
				g[i][j+1] = p-1;
				anse[p-1] = 1;
			}
		}
		bool hasdia = 0;
		for(int i = 0; i < n && !hasdia; ++ i)
			if(anse[i] == 0)
			{
				memset(vis, 0, sizeof(vis));
				hasdia = dfs(i);
			}

		out<<"Case #"<<itest<<": "<<(hasdia ? "Yes" : "No")<<endl;
	}

	in.close();
	out.close();

	return 0;
}