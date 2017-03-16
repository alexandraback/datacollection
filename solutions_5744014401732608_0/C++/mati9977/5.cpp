#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

ifstream goo;
ofstream gle;

int tab[59][59];

void solve()
{
	int n;
	long long m,a,b=1;
	goo>>n>>m;
	for(int i=1; i<=n; i++) tab[i][n]=0;
	for(int i=1; i<n-1; i++) b*=2;
	if(b<m)
	{
		gle<<"IMPOSSIBLE\n";
		return;
	}
	else gle<<"POSSIBLE\n";
	for(int i=1; i<n; i++) for(int j=i+1; j<n; j++) tab[i][j]=1;
	if(m==b)
	{
		tab[1][n]=1;
		m--;
	}
	a=2;
	while(m>0)
	{
		if(m%2==1)
		{
			tab[a][n]=1;
			m--;
		}
		a++;
		m/=2;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++) gle<<tab[i][j];
		gle<<"\n";
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//goo.open("C:\\Users\\Mateusz\\Desktop\\goo.in");
	goo.open("C:\\Users\\Mateusz\\Downloads\\B-small-attempt0 (2).in");
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
