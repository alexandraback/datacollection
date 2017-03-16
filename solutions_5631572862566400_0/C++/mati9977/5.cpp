#include<bits/stdc++.h>
using namespace std;

ifstream goo;
ofstream gle;
int tab[1009],X,n,c;

void DFS(int u, vector<bool> col, int x, int a)
{
	col[u]=1;
	x++;
	int b=tab[u];
	if(b!=a)
	{
		if(col[b]==1)
		{
			if(c!=b) return;
			X=max(X,x);
			return;
		}
		else DFS(b,col,x,u);
	}
	else
	{
		for(int i=1; i<=n; i++) if(col[i]==0) DFS(i,col,x,u);
		X=max(X,x);
	}
	return;
}

void solve()
{
	X=0;
	goo>>n;
	for(int i=1; i<=n; i++) goo>>tab[i];
	vector<bool> col;
	col.resize(n+9, 0);
	for(int i=1; i<=n; i++)
	{
		c=i;
		DFS(i,col,0,-1); 
	}
	gle<<X<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	goo.open("C:\\Users\\Mateusz\\Downloads\\C-small-attempt0 (1).in");
	//goo.open("C:\\Users\\Mateusz\\Desktop\\goo.in");
	gle.open("C:\\Users\\Mateusz\\Desktop\\gle.out");
	int t;
	goo>>t;
	for(int i=1; i<=t; i++)
	{
		gle<<"Case #"<<i<<": ";
		solve();
	}
	goo.close();
	gle.close();
	return 0;
}
