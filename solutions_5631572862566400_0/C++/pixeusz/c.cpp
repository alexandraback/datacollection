#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

#define LIM 1003
int F[LIM];
vector<int> G[LIM];
bool isInless[LIM];
bool isPaired[LIM];
int revPathLens[LIM];
bool used[LIM];

void SolveCase(int caseId);
void Clear(int n);
int LongestCycle(int n);
void ProcInless();

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

void SolveCase(int caseId)
{
	int n;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &F[i]);
		G[F[i]].push_back(i);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		if(G[i].size() == 0)
			isInless[i] = true;
		else if(i < F[i] && F[F[i]] == i)
			isPaired[i] = isPaired[F[i]] = true;
	}
	
	int result = LongestCycle(n);
	
	int pairedMax = 0;
	for(int i = 1; i <= n; ++i)
		if(isPaired[i])
			pairedMax += revPathLens[i] + 1;
			
	result = max(result, pairedMax);

	printf("Case #%d: %d\n", caseId, result);
	Clear(n);
}

int LongestCycle(int n)
{
	int result = 0;
	
	for(int v0 = 1; v0 <= n; ++v0)
	{
		bool inless = isInless[v0];
		memset(used+1, 0, n);
		used[v0] = true;
		int v = v0;
		int len = 1;
		while(F[v] != v0 && !used[F[v]])
		{
			v = F[v];
			used[v] = true;
			if(inless && isPaired[v])
			{
				revPathLens[v] = max(revPathLens[v], len);
				inless = false;
			}
			++len;
		}
		if(F[v] == v0)
			result = max(result, len);
	}
	
	return result;
}

void Clear(int n)
{
	memset(isInless+1, 0, n);
	memset(isPaired+1, 0, n);
	memset(revPathLens+1, 0, n*sizeof(int));
	for(int i = 1; i <= n; ++i)
		G[i].clear();
}

