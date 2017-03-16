#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <map>
#include <math.h>
using namespace std;

#define BOOL int
#define TRUE 1
#define FALSE 0
int readi() { int a; scanf( "%d", &a ); return a; }


 BOOL DEBUGIN = FALSE;
 BOOL DEBUGOUT = FALSE;

int T, N, D;
#define min(a, b) (a<b?a:b)

char G[1000+1][1000+1];
char visited[1000+1];

int check(int start)
{
    vector<int> m;

	int i, v, u;
	m.push_back(start);
    visited[start]++;
	
	while(m.size() > 0) {
		v = m[0];

		if (visited[v] >= 2) return 1; 
		m.erase(m.begin());
		
		for (i = 1; i <= 1000; ++i)
		{
			u = G[v][i];
			if (u == 0) break;
		    m.push_back(u);
			visited[u]++;
		}
    
	}

	return 0;
}

int main(int argc, char* argv[])
{
	int i, j, k;
	if (!DEBUGIN) freopen("A-large.in","rt",stdin);
	if (!DEBUGOUT) freopen("A-large.out","wt",stdout);

	T = readi();
	for (int testcase = 1; testcase <= T; testcase++)
	{
		memset(G, 0x00, 1001 * 1001 * sizeof(char));

		N = readi(); 
		for (i = 1; i <= N; i++)
		{
			D = readi();
			k = 1;
			for (j = 1; j <= D; j++)
		    {
			    G[i][k] = readi();
				k++;
		    }
		}
		
		int result = 0;
		for (i = 1; i <= N; i++)
		{
     		memset(visited, 0x00, 1001 * sizeof(char));

			result = result + check(i);
		}

		if (result == 0)
		    printf("Case #%d: No", testcase);
		else
			printf("Case #%d: Yes", testcase);
		printf("\n");
	}

	return 0;
}
