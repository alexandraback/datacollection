#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int m, n;
int tokens[200];
int preset[200];
int postset[200][200];
int fired[200];

int res[200];

int seen[200];
int candidate;

bool go(int p)
{
	if (!seen[p]) seen[p] = 1;
	if (seen[p] != 2 && tokens[p] > 0) return true;

	for(int t = 0; t < n; t++)
	if (!fired[t] && postset[t][p] > 0)
	{
		if (t == candidate) return true;
		if (!seen[preset[t]] && go(preset[t])) return true;
	}

	return false;	
}

bool good(int t)
{
	int p = preset[t];

	if (!tokens[p]) return false;

	if (tokens[p] > 1) return true;

	int conflict = 0;
	for(int i = 0; i < n; i++) if (!fired[i] && preset[i] == p) conflict++;
	if (conflict < 2) return true;

	// single token in p

	memset(seen, 0, sizeof seen);

	seen[p] = 2;

	candidate = t;
	return go(p);
}

bool solve()
{
	memset(fired, 0, sizeof fired);
	for(int step = 0; step < n; step++)
	{
		bool deadlock = true;
		for(int i = 0; i < n; i++)
		if (!fired[i] && good(i))
		{
			tokens[preset[i]]--;
			for(int j = 0; j < 200; j++) tokens[j] += postset[i][j];

			//printf("fire %d\n", i + 1);
			fired[i] = true;
			res[step] = i;
			deadlock = false;
			break;
		}
		if (deadlock) return false;
	}
	for(int i = 0; i < n; i++) printf(" %d", res[i] + 1);
	puts("");
	return true;
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d:", tt);
		
		scanf("%d %d", &m, &n);

		memset(tokens, 0, sizeof tokens);
		memset(postset, 0, sizeof postset);

		for(int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x); x--;
			tokens[x]++;
		}
		
		for(int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			preset[i] = x - 1;
			for(int j = 0; j < y; j++)
			{
				int z;
				scanf("%d", &z);
				postset[i][z - 1]++;
			}
		}

		if (!solve()) puts(" IMPOSSIBLE");
	}
	return 0;
}