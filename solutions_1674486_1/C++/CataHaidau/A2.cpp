#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define maxN 1010
#define PB push_back

vector <int> list[maxN];
int cont[maxN], ok;


void DFS (int nod)
{
	if (ok) return;
	
	for (unsigned int i = 0; i < list[nod].size(); ++ i)
	{
		int nod2 = list[nod][i];
		
		if (cont[nod2] && cont[nod2] != nod)
		{
			ok = 1;
			return;
		}
		
		cont[nod2] = nod;
		DFS (nod2);
	}
}


int main()
{
	freopen ("date.in", "r", stdin);
	freopen ("date.out", "w", stdout);
	
	int T;
	scanf ("%d", &T);
	
	for (int t = 1; t <= T; ++ t)
	{
		int N;
		scanf ("%d", &N);
		
		for (int i = 1; i <= N; ++ i)
		{
			int M;
			scanf ("%d", &M);
			
			for (int j = 1; j <= M; ++ j)
			{
				int x;
				scanf ("%d", &x);
				list[x].PB (i);
			}
		}
		
		for (int i = 1; i <= N; ++ i)
		{
			memset (cont, 0, sizeof (cont));
			ok = 0;
			DFS (i);
			
			if (ok) break;
		}
		
		if (ok) printf ("Case #%d: Yes\n", t);
		else printf ("Case #%d: No\n", t);
		
		for (int i = 1; i <= N; ++ i) list[i].clear();
	}
	
	return 0;
}
