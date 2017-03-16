#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int deg[MAXN],out[MAXN],dep[MAXN];
bool vis[MAXN];
set < pair<int,int> > S;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for (int tc = 1; tc <= t; ++tc)
	{
		int n;
		cin>>n;
		memset(deg, 0, sizeof deg);
		memset(dep, 0, sizeof dep);
		memset(vis, false, sizeof vis);
		S.clear();
		for (int i = 1; i <= n; ++i)
		{
			cin>>out[i];
			deg[out[i]]++;
		}
		for (int i = 1; i <= n; ++i)
			S.insert(make_pair(deg[i],i));
		while(true)
		{
			assert(!S.empty());
			pair <int,int> top = *S.begin();
			if(top.first > 0)
				break;
			S.erase(top);
			int pos = top.second;
			vis[pos] = true;
			int x = out[pos];
			// update deg
			S.erase(make_pair(deg[x],x));
			deg[x]--;
			S.insert(make_pair(deg[x],x));
			// update dep
			dep[x] = max(dep[x],1+dep[pos]);
		}
		int ans = 0, c2 = 0;
		for (int i = 1; i <= n; ++i)
		{
			if(!vis[i])
			{
				int temp = 0, pos = i;
				while(!vis[pos])
				{
					vis[pos] = true;
					temp++;
					pos = out[pos];
				}
				ans = max(ans,temp);
				if(temp == 2)
				{
					int x = i, y = out[i];
					c2+=(temp+dep[x]+dep[y]);
				}
			}
		}
		ans = max(ans,c2);
		cout<<"Case #"<<tc<<": "<<ans<<"\n";
	}
	return 0;
}
