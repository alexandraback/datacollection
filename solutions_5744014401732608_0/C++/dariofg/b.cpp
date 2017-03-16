#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

vector<vector<long long> > prod(vector<vector<long long> >&a, vector<vector<long long> >&b)
{
	vector<vector<long long> > res = vector<vector<long long> > (a.size(),vector<long long>(a.size()));
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<a.size();j++)
		{
			for(int k=0;k<a.size();k++)
				res[i][j]+=a[i][k]*b[k][j];
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	for(int I=1;I<=T;I++)
	{
		int b,m;
		cin >> b >> m;
		cout << "Case #" << I << ": ";
		int pot = (b-1)*(b-1)+b-2;
		if((m-1)>>(b-2))
		{
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		int aaa = 1;
		for(int i=0;i<pot;i++)
			aaa+=aaa;
		for(int i=0;i<aaa;i++)
		{
			int a = i;
			vector<vector<long long> > v(b,vector<long long>(b));
			for(int j=0;j<b-1;j++)
			{
				for(int k=1;k<b;k++)
				{
					if(j==k)
						continue;
					v[j][k]=a&1;
					a/=2;
				}
			}
			int res = v[0][b-1];
			vector<vector<long long> > mr = v;
			for(int j=0;j<b-1;j++)
			{
				mr = prod(mr,v);
				res+=mr[0][b-1];
			}
			int suma = 0;
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<b;k++)
					suma+=mr[j][k];
			}
			if(!suma && res ==m)
			{
				cout << "POSSIBLE" << endl;
				for(int j=0;j<b;j++)
				{
					for(int k=0;k<b;k++)
						cout << v[j][k];
					cout << endl;
				}
				goto bbb;
			}
		}
		cout << "IMPOSSIBLE" << endl;
		bbb:;
	}
}	
