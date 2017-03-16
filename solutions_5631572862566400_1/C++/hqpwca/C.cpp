#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <functional>
#include <list>
#include <set>
#include <sstream>
#define ll long long

using namespace std;

int ans=0,ans2=0,cp=0;

int n,l[1005];
vector<int> E[1005],C[1005];
bool vis[1005],cir[1005];
int num[1005];

void dfs(int now)
{
	//cout<<now<<endl;
	if(cir[now])return;
	if(vis[now]){
		int t=l[now];
		cir[now]=true;
		C[cp].push_back(now);
		num[cp]++;
		while(t!=now){
			num[cp]++;
			cir[t]=true;
			C[cp].push_back(t);
			t=l[t];
		}
		cp++;
		return;
	}
	vis[now]=true;
	dfs(l[now]);
}

int get_depth(int now)
{
	int res=1;
	for(auto i:E[now])
	{
		if(cir[i])continue;
		res=max(res,get_depth(i)+1);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);

	//while(cin>>n)

	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		memset(num,0,sizeof(num));
		memset(cir,0,sizeof(cir));
		ans=ans2=cp=0;
		cin>>n;
		for(int i=0;i<=n;i++)
			E[i].clear(),C[i].clear();
		for(int i=1;i<=n;i++){
			cin>>l[i];
			E[l[i]].push_back(i);
		}
		//cout<<"here"<<endl;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(!vis[i])
				dfs(i);
		}
		//cout<<"here"<<endl;
		for(int i=0;i<cp;i++)
		{
			if(num[i]>2)ans=max(ans,num[i]);
			else
				ans2+=get_depth(C[i][0])+get_depth(C[i][1]);
		}
		//cout<<"here"<<endl;
		cout<<"Case #"<<cas<<": "<<max(ans,ans2)<<endl;;
		//cout<<"Case "<<cas<<": ";
	}

	return 0;
}
