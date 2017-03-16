
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> inh;
bool sv(const vector<inh> &cs)
{
	int n=cs.size();
	for(int j=0;j<n;++j)
	{
		vector<int> cache(n+1);
		inh active=cs[j];
		for(;;)
		{
			inh na;
			for(int k=0;k<active.size();++k)
			{
				int a=active[k];
				if(cache[a])
					return true;
				cache[a]=1;
				for(int l=0;l<cs[a-1].size();++l)
				{
					na.push_back(cs[a-1][l]);
				}
			}
			active=na;
			if(active.empty())break;
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		int n;
		cin>>n;
		vector<inh> cs(n);
		for(int j=0;j<n;++j)
		{
			int m;
			cin>>m;
			if(m==0)continue;
			for(int k=0;k<m;++k)
			{
				int x;
				cin>>x;
				cs[j].push_back(x);
			}
		}
		bool res=sv(cs);
		
		printf("Case #%d: %s\n",i,res?"Yes":"No");
	}
	return 0;
}

