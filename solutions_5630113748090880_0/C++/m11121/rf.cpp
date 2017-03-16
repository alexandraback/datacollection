#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int cnt[2501];
int main()
{
	int t;
	cin>>t;
	for(int ic=1;ic<=t;++ic)
	{
		memset(cnt,0,sizeof cnt);
		int n;
		cin>>n;
		for(int i=0;i<2*n-1;++i)
		{
			for(int j=0;j<n;++j)
			{
				int tmp;
				cin>>tmp;
				cnt[tmp]++;
			}
		}
		vector<int> ans;
		for(int i=1;i<=2500;++i)
		{
			if(cnt[i]%2==1) 
				ans.push_back(i);
		}
		cout<<"Case #"<<ic<<":";
		for(auto i:ans)cout<<" "<<i;
		endl(cout);
	}
	return 0;

}
