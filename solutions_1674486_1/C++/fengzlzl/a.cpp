#include <string> 
#include <vector> 
#include <algorithm> 
#include <numeric> 
#include <iostream> 
#include <sstream> 
#include <queue> 
#include <set> 
#include <map> 
#include <list> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cassert> 
#include <cmath> 
#include <complex> 
#include <cstring>
using namespace std; 

const int maxn = 1000+10;

int to[maxn][20];
int m[maxn];

int din[maxn];
int deg[maxn];
int n;
queue<int> q;

bool BFS(int x)
{
	int i, y;
	
	memset(deg, 0, sizeof(deg));
	
	while (!q.empty()) q.pop();
	q.push(x);	
	while (!q.empty())
	{
		x=q.front();
		q.pop();
		for (i=0; i<m[x]; i++)
		{
			y = to[x][i];
			deg[y]++;
			if (deg[y]>1) return true;
			q.push(y);
		}
	}
	return false;
}

int main() 
{
	freopen("a.in", "r", stdin);
	freopen("aout.txt", "w", stdout);
	int T, i, j, cas=0; 
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(din, 0, sizeof(din));
		memset(to, 0, sizeof(to));
		for (i=0; i<n; i++)
		{
			scanf("%d", &m[i]);
			for (j=0; j<m[i]; j++)
			{
				scanf("%d", &to[i][j]);
				to[i][j]--;
				din[ to[i][j] ]++;
			}
		}
		bool flag = false;
		for (i=0; i<n; i++)
		  if (BFS(i)) break;
		printf("Case #%d: ", ++cas);

		if (i==n) printf("No\n");
		else printf("Yes\n");    
	}
        return 0; 

} 


