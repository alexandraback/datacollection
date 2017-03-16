#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
int in[1003],ar[1003];
map<vector<int>,int> mp;
int sol(vector<int> rec)
{
	if(mp.find(rec)!=mp.end())
		return mp[rec];
	//vector<int> bst=rec;
	int ans=1e9;
	for(int i=9;i>=3;i--)
	{
		if(!rec[i])
			continue;
		int tmp=rec[i];
		rec[i]=0;
		for(int j=1;j<=i/2;j++)
		{
			rec[j]+=tmp;
			rec[i-j]+=tmp;
			if(ans>sol(rec)+tmp)
			{
				ans=sol(rec)+tmp;
				//for(int k=0;k<10;k++)
				//	bst[k]=rec[k];
			}
			rec[j]-=tmp;
			rec[i-j]-=tmp;
		}
		rec[i]=tmp;
	}
	for(int i=9;i>=0;i--)
		if(rec[i])
			return mp[rec]=min(ans,i);
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		int n;
		scanf("%d",&n);
		memset(ar,0,sizeof(ar));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&in[i]);
			ar[in[i]]++;
		}
		vector<int> rec(ar,ar+10);
		printf("Case #%d: %d\n",cas,sol(rec));
	}
	return 0;
}
