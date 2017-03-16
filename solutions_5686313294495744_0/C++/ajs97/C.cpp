#include <bits/stdc++.h>
using namespace std;
#define pss pair<string,string>
#define x first
#define y second

pss a[17];
set<int> d;
vector<int> c;
vector<vector<int> > first,second;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	string str="Case #";

	for(int w=1;w<=t;w++)
	{
		int n;
		first.clear();
		second.clear();

		cin>>n;
		first.resize(n+5);
		second.resize(n+5);

		for(int i=0;i<n;i++)
			cin>>a[i].x>>a[i].y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j==i)continue;
				if(a[i].x==a[j].x)
					first[i].push_back(j);
				if(a[i].y==a[j].y)
					second[i].push_back(j);
			}
		}
		int ans=0;
		for(int mask=0;mask<(1<<n);mask++)
		{
			c.clear();
			d.clear();
			int cur1=0,cur2=0;
			for(int i=0;i<n;i++)
			{
				if(mask&(1<<i))
					c.push_back(i);
				else d.insert(i);
			}
			//c is faked
			bool posi=true;
			for(int i=0;i<c.size();i++)
			{
				bool t1=false,t2=false;
				for(int j=0;j<first[c[i]].size();j++)
					if(d.find(first[c[i]][j])!=d.end())
						t1=true;
				for(int j=0;j<second[c[i]].size();j++)
					if(d.find(second[c[i]][j])!=d.end())
						t2=true;
					t1=t1&&t2;
					posi=posi&&t1;
			}
			if(posi)
				ans=max(ans,(int)c.size());
		}
		cout<<str<<w<<": "<<ans<<endl;
	}		

}