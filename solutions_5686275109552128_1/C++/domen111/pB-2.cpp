#include<bits/stdc++.h>
using namespace std;
struct item{
	int cnt;
	int ori_val;
	int val()const
	{
		return (ori_val+cnt)/(cnt+1);
	}
	bool operator<(item b)const
	{
		return val()<b.val();
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	int no=1;
	while(no<=T)
	{
		int n;
		cin>>n;
		priority_queue<item> pq;
		for(int i=0;i<n;i++)
		{
			int t;
			cin>>t;
			pq.push({0,t});
		}
		int ans=pq.top().val();
		for(int i=1;i<=1000;i++)
		{
			item mx=pq.top();
			pq.pop();
			mx.cnt++;
			pq.push(mx);
			ans=min(ans,pq.top().val()+i);
		}
		printf("Case #%d: %d\n",no++,ans);
	}
}
