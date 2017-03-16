#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int cyc(int *f,int n,int start)
{
	bool v[n+1];
	for(int i=1;i<=n;i++)
		v[i]=false;
	int curr=start,fr;
	int count=1;
	while(1)
	{
		fr=f[curr];
		if(fr==start)
			return count;
		else if(v[fr])
			return 0;
		else
		{
			v[fr]=true;
			count++;
			curr=fr;
		}
	}
}
int find(int *f,int n,int target)
{
	bool v[n+1];
	int i,j,curr,count,ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			v[j]=false;
		}
		curr=i,count=0;
		while(1)
		{
			if(curr==target)
				break;
			else if(v[curr]||(curr==f[target]))
			{
				count=0;
				break;
			}	
			else
			{
				v[curr]=true;
				count++;
				curr=f[curr];
			}
		}
		if(count>ans)
			ans=count;
	}
	return ans;
}
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		int n;
		cin>>n;
		int f[n+1];
		for(int i=1;i<=n;i++)
			cin>>f[i];
		int ans1=0,ans2=0,count,j;
		for(int i=1;i<=n;i++)
		{
			count=cyc(f,n,i);
			if(count==2)
			{
				j=f[i];
				count+=find(f,n,i)+find(f,n,j);
				ans2+=count;
			}
			else
			{
				if(count>ans1)
					ans1=count;
			}
		}
		ans2/=2;
		int ans=(ans1>=ans2)?ans1:ans2;
		cout<<"Case #"<<cno<<": "<<ans<<endl;
	}
	return 0;
}
