#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int cnt[2600];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T,no=0;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		ans.clear();
		memset(cnt,0,sizeof cnt);
		for(int i=0;i<n*2-1;i++)
			for(int j=0;j<n;j++)
			{
				int v;
				cin>>v;
				cnt[v]++;
			}
		for(int i=1;i<=2500;i++)
			if(cnt[i]%2==1)
				ans.push_back(i);
		sort(ans.begin(), ans.end());
		cout<<"Case #"<<++no<<":";
		for(int i=0;i<n;i++)
			cout<<' '<<ans[i];
		cout<<'\n';
	}
}