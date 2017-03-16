#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
vector < vector <int> > V;
vector <bool> col;
bool p=0;
void dfs(int x)
{
//	printf ("%dfs dla %d\n", x);
	if (col[x])
	{
		p=1;
		return;
	}
	col[x]=1;
	for (int i=0; i<V[x].size(); i++) dfs(V[x][i]);
}
int main ()
{
	int t;
	scanf ("%d", &t);
	for (int tt=1; tt<=t; tt++)
	{
		p=0;
		V.clear();
		int n;
		scanf ("%d", &n);
		V.resize(n+1);
		for (int i=1; i<=n; i++)
		{
			int m;
			scanf ("%d", &m);
			while (m--)
			{
				int a;
				scanf ("%d", &a);
				V[a].push_back(i);
			}
		}
		for (int i=1; i<=n; i++) 
		{
			col.clear();
			col.resize(n+1);
			dfs(i);
			if (p) break;
		}
		if (p) 	printf ("Case #%d: Yes\n", tt);
		else 	printf ("Case #%d: No\n", tt);
	}
//system ("pause");
return 0;
}
