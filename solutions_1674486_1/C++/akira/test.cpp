#include <iostream>
using namespace std;
int f1[1001];
int f2[1001];
int tp[1001][1001];

int dfs(int tr)
{
	for (int i = 1; i <= tp[tr][0]; i++)
	{
		if (f1[tp[tr][i]]) return 1;
		else
		{
			f1[tp[tr][i]] = 1;
			f2[tp[tr][i]] = 1;
			if (dfs(tp[tr][i]) == 1) return 1;
		}
	}
	return 0;
}

int main()
{
	int T,n,flag;
	cin>>T;
	for (int j = 0; j < T; j++)
	{
		flag = 0;
		for(int i = 0; i <= 1000;i++) f2[i]=0;
		cin>>n;
		for (int k = 1; k <= n; k++)
		{
			cin>>tp[k][0];
			for (int l = 1; l <= tp[k][0]; l++)
			{
				cin>>tp[k][l];
			}
		}
		for (int m = 1; m <= n; m++)
		{
			
			if (f2[m] == 0)
			{
				for(int i = 0; i <= 1000;i++) f1[i]=0;
				flag = dfs(m);
			}
			if (flag) break;
		}
		cout<<"Case #"<<j+1<<": ";
		if (flag)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
		cout<<endl;
	}
	return 0;
}