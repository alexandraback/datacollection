#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

ifstream goo;
ofstream gle;

typedef pair<int,int> par;
typedef pair<int,par> para;
int tab[19][19], tac[19][19], tad[19][19];

void solve()
{
	for(int i=1; i<=10; i++) for(int j=1; j<=10; j++) tab[i][j]=tac[i][j]=tad[i][j]=0;
	vector<para> v;
	int n,a,b,c,w=0;
	goo>>a>>b>>c>>n;
	for(int i=1; i<=a; i++)
	{
		for(int j=1; j<=b; j++)
		{
			for(int k=1; k<=c; k++)
			{
				if(tab[i][j]<n && tac[i][k]<n & tad[j][k]<n)
				{
					tab[i][j]++;
					tac[i][k]++;
					tad[j][k]++;
					v.push_back(para(i,par(j,k)));
					w++;
				}
			}
		}
	}
	gle<<w<<"\n";
	for(int i=0; i<v.size(); i++) gle<<v[i].f<<" "<<v[i].s.f<<" "<<v[i].s.s<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	//goo.open("C:\\Users\\Mateusz\\Desktop\\goo.in");
	goo.open("C:\\Users\\Mateusz\\Downloads\\C-small-attempt0 (3).in");
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
