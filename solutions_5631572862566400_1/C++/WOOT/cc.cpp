#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<string.h>
#include<stack>
#include<vector> 
#include<cmath>
#include<algorithm>
using namespace std;

int T=0;
int num=0;
int a[1100];
typedef pair<int ,int >pii;
typedef pair< pii, int> piii;
int ans[1100];
void Gao()
{
	int n;
	printf("Case #%d: ",++num);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int res=0;
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++)
	{
		if (a[a[i]]==i)
			ans[i]=max(ans[i],2);
		bool hsh[1100];
		memset(hsh,0,sizeof(hsh));
		int cur=i;
		int cnt=0;
		vector<int> cycle;
		while (!hsh[cur])
		{
			cycle.push_back(cur);
			cnt+=1;
			hsh[cur]=true;
			cur=a[cur];
		}
		if (a[cycle[cycle.size()-1]]==i)
			res=max(res,(int)cycle.size());
		else
			ans[cycle[cycle.size()-1]]=max(ans[cycle[cycle.size()-1]],(int)cycle.size());
	}
	int temp=0;
	for (int i=1;i<=n;i++)
	{
		if (i==a[a[i]] && i<a[i])
		{
			temp+=max(max(ans[i],ans[i] + ans[a[i]] - 2),ans[a[i]]);
		}
	}
	cout<<max(res,temp)<<endl;
}
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	cin>>T;
	while (T--)
		Gao();
} 

