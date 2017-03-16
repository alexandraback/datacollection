#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main()
{
	int test;
	cin>>test;
	for(int z=1;z<=test;z++)
	{
		int a,b,c,kk;
		cin>>a>>b>>c>>kk;
		vector< vi > v;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=1;k<=c;k++)
				{
					vi u;
					u.push_back(i);
					u.push_back(j);
					u.push_back(k);
					v.push_back(u);
				}
			}
		}
		vector < vi > ans;
		map<pii,int> c1,c2,c3;
		for(int x=0;x<v.size();x++)
		{
			vi u = v[x];
			int i = u[0],j = u[1], k=u[2];
			c1[pii(i,j)]++;
			c2[pii(j,k)]++;
			c3[pii(k,i)]++;
			if(c1[pii(i,j)]>kk || c2[pii(j,k)]>kk || c3[pii(k,i)]>kk)
			{
			c1[pii(i,j)]--;
			c2[pii(j,k)]--;
			c3[pii(k,i)]--;
			}
			else ans.push_back(u);
		}
		cout<<"Case #"<<z<<": "<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
		{
			vi u = ans[i];
			cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<endl;
		}
	}
}
