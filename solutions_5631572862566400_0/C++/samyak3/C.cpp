#if 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

FILE* pF;

FILE* pAnsF;

int N;
int gSource;
bool g1[11][11];
bool g2[11][11];
bool visited[11];
void resetV()
{	
	for (int i = 0; i <= 10; i++)
	{
		visited[i] = false;
	}
}

void reset()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			g1[i][j] = false;
			g2[i][j] = false;
		}
	}
	for (int i = 0; i <= 10; i++)
	{
		visited[i] = false;
	}
}
int dfs(int source, int dest, bool found)
{
	if (dest == gSource)
	{
		return 0;
	}
	if (dest == source)
	{
		return 0;
	}
	if (dest != gSource && visited[dest])
	{
		return -999;
	}
	visited[source] = true;
	visited[dest] = true;
	bool bffneeded = true;
	int ans = -99999; 
	if (g1[dest][source] || found)
	{
		bffneeded = false;
		ans = 1;
	}
	
	if (bffneeded)
	{
		for (int i = 1; i <= 10; i++)
		{
			if (g1[dest][i])
			{
				ans = max(ans,1+ dfs(dest, i, false));
			}
		}
		return ans;
	}
	else
	{
		for (int i = 1; i <= 10; i++)
		{
			if (g2[dest][i])
			{
				ans = max(ans, 1+dfs(dest, i, true));
			}
		}
		return max(ans, 0);
	}
	
}
int main()
{
	freopen_s(&pF, "Text.txt", "r", stdin);
	freopen_s(&pAnsF, "OC.txt", "w", stdout);

	int C;

	cin >> C;

	for (int c = 1; c <= C; c++)
	{
		cin >> N;
		
		int bff;
		for (int i = 1; i <= N; i++)
		{
			cin >> bff;
			g1[i][bff] = true;
			g2[bff][i] = true;			
		}
		int ans = 0;
		for (int s = 1; s <= 10; s++)
		{
			gSource = s;
			for (int t = 1; t <= 10; t++)
			{
				if (g1[s][t])
				{
					ans = max(ans, 1 + dfs(s, t, false));
				}
			}
			resetV();
		}
		cout << "Case #" << c << ": ";
		cout << ans << endl;
		reset();
	}

	return 0;
}

#endif