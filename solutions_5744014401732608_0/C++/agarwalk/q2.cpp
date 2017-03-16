#include<bits/stdc++.h>

#define pb(x) push_back(x);
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define inf 1<<30
#define ll long long   

using namespace std;

int main()
{
	int n,q,b,m,t,x;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>b>>m;
		cout<<"Case #"<<k<<": ";
		int arr[b+1][b+1];
		memset(arr,0,sizeof arr);
		int cur = 1;
		int temp = (b*b - 3*b + 4)/2;
		if(m>temp)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		cout<<"POSSIBLE"<<endl;
		arr[1][b]=1;
		m--;
		cur=1;
		int next=2;
		while(m>0)
		{
			arr[cur][next]=1;
			arr[next][b]=1;
			m--;
			next++;
			if(next==b)
			{
				cur++;
				next=cur+1;
			}
		}
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=b;j++)
				cout<<arr[i][j];
			cout<<endl;
		}
	}
	return 0;
}
