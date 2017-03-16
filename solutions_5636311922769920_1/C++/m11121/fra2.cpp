#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		int k,c,s;
		cin>>k>>c>>s;
		cout<<"Case #"<<ic<<":";
		if(k==1){ cout<<" 1"<<endl;continue;}
		if(c==1)
		{
			if(s!=k) cout<<" IMPOSSIBLE\n";
			else
			{
				for(int i=1;i<=k;++i)
				{
					cout<<" "<<i;


				}
				endl(cout);
			}
			continue;
		}
		vector<long long> ans;
		long long cont = 1;
		for(int i=1;i<c;++i) cont*=k;
		for(int i=1;i<=k;i+=2)
		{
			ans.push_back((i-1)*cont+i+1);
		}
		if(ans.size()>s|| s==1 ) cout<<" IMPOSSIBLE\n";
		else
		{
			for(auto p:ans) cout<<" "<<p;
			endl(cout);
		}
	}
	return 0;
}
