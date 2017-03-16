#include<bits/stdc++.h>
using namespace std;

ifstream goo;
ofstream gle;
int tab[3000];

void solve()
{
	int n,a,m;
	for(int i=1; i<=2500; i++) tab[i]=0;
	goo>>n;
	m=(2*n)-1;
	m*=n;
	for(int i=1; i<=m; i++)
	{
		goo>>a;
		tab[a]++;
	}
	for(int i=1; i<=2500; i++)
	{
		if(n==0) break;
		if(tab[i]%2==1)
		{
			gle<<i<<" ";
			n--;
		}
	}
	gle<<"\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	goo.open("C:\\Users\\Mateusz\\Downloads\\B-small-attempt0.in");
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
