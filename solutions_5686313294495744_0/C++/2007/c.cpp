#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> form;
int ans[2000000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	int n;
	for (int tc = 1; tc <= T; ++tc)
	{
		cin>>n;
		vector<form> v1(n);
		vector<pair<int,int> > v(n);
		map<string,int> mp;
		int ct=0;
		for(int i=0; i<n; i++)
		{
			cin>>v1[i].first>>v1[i].second;
			if(!mp.count(v1[i].first))
				mp[v1[i].first]=ct++;
			if(!mp.count(v1[i].second))
				mp[v1[i].second]=ct++;
		}
		for(int i=0; i<n; i++)
		{
			v[i].first = mp[v1[i].first];
			v[i].second = mp[v1[i].second];
		}
		cout<<"Case #"<<tc<<": ";
		int tot = (1<<n);
		fill(ans,ans+tot,0);
		tot--;
		for(int i=0; i<=tot; i++)
		{
			int mask=1;
			int ft[ct],sc[ct];
			fill(ft,ft+ct,0);
			fill(sc,sc+ct,0);
			for(int j=0; j<n; j++)
			{
				if((mask&i)!=0)
				{
					ft[v[j].first]++;
					sc[v[j].second]++;
				}
				mask*=2;
			}
			mask=1;
			int deb = 0;
			for(int j=0; j<n; j++)
			{
				if((mask&i)!=0)
				{	
					if((ft[v[j].first]>1)&&(sc[v[j].second]>1))
						ans[i] = max(ans[i], 1+ans[i-mask]);
					else
						ans[i] = max(ans[i], ans[i-mask]);
				}
				mask*=2;
			}
		}
		cout<<ans[tot]<<"\n";
	}
}