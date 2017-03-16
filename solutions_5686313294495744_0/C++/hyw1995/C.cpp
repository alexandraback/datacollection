#include<bits/stdc++.h>
using namespace std;
map<string,int> Map1,Map2;
vector<pair<string,string> > a;
bool flag[100];
int ans;
void dfs(int i,int n)
{
	if (i == n)
	{
		int now = 0;
		for (int j=0;j<n;j++)
			if (flag[j]==false) now++;
		if (now <= ans) return;
		Map1.clear();Map2.clear();
		for (int i=0;i<n;i++)
			if (flag[i])
			{
				Map1[a[i].first] = true;
				Map2[a[i].second] = true;
			}
		for (int i=0;i<n;i++)
			if (flag[i]==false)
			{
				if (Map1[a[i].first]==false || Map2[a[i].second]==false) return;
			}
		ans = now;
		return;
	}
	flag[i] = true; dfs(i+1,n);
	flag[i] = false; dfs(i+1,n);
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T,test = 0;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		a.clear();
		for (int i=0;i<n;i++)
		{
			pair<string,string> tmp;
			cin>>tmp.first>>tmp.second;
			a.push_back(tmp);
		}
		ans = -1;
		dfs(0,n);
		printf("Case #%d: %d\n",++test,ans);
	}
}
