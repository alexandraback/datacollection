#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int e[1005][2],dist[1005];
bool vis[1005];
vector<int>ve[1005];

int work1(int st)
{
	for (int i=1;i<=n;i++) vis[i]=false;
	vis[st]=true;
	dist[st]=0;
	int qu[1005];
	int head=0,tail=1;
	qu[0]=st;
	vis[st]=true;
	while (head<tail)
	{
		int p=qu[head++];
		int q=e[p][1];
		if (!vis[q])
		{
			vis[q]=true;
			dist[q]=dist[p]+1;
			qu[tail++]=q;
		}
		else if (q==st) return dist[p]+1;
	}
	return -1;
}

int work3(int x,int y)
{
	int ans=0;
	int qu[1005];
	for (int i=1;i<=n;i++) vis[i]=false;
	vis[x]=true;
	qu[0]=x;
	dist[x]=0;
	int head=0,tail=1;
	while (head<tail)
	{
		int p=qu[head++];
		for (int i=0;i<ve[p].size();i++)
		{
			int q=ve[p][i];
			if (q==y) continue;
			if (vis[q]) continue;
			dist[q]=dist[p]+1;
			vis[q]=true;
			qu[tail++]=q;
			ans=max(ans,dist[q]);
		}
	}
//	cout <<x<<' '<<y<<' '<<ans+1<<endl;
	return ans+1;
}

int work2(int x,int y)
{
	if (x>y) return 0;
//	cout<<"!"<<x<<' '<<y<<endl;
	return work3(x,y)+work3(y,x);
}

int work()
{
	cin>>n;
	for (int i=1;i<=n;i++) ve[i].clear();
	for (int i=1;i<=n;i++)
	{
		e[i][0]=i;
		cin>>e[i][1];
		ve[e[i][1]].push_back(i);
	}
//	for (int i=1;i<=n;i++) cout<<e[i][0]<<' '<<e[i][1]<<endl;
	int ans=0,ans1=0;
	for (int i=1;i<=n;i++) ans=max(ans,work1(i));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (e[i][1]==j&&e[j][1]==i) ans1+=work2(i,j);
	ans=max(ans,ans1);
//	for (int i=1;i<=n;i++) cout<<i<<' '<<work1(i)<<endl;
	return ans;

}

int main()
{
	freopen ("small.in","r",stdin);
	freopen ("small.out","w",stdout);
	int T;
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cout<<"Case #"<<i<<": ";
		cout<<work()<<endl;
	}
	return 0;
}