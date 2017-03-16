#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		int n;
		cin>>n;
		double a[n],b[n];
		int i,j;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		cout<<"Case #"<<u-t<<": ";
		sort(a,a+n);
		sort(b,b+n);
		int c[n],d[n];
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		j=0;
		int k=n-1;
		for(i=n-1;i>=0;i--)
		{
			if(c[i]==0)
			{
				if(a[i]>b[k])
				{
					c[i]=1;
					d[i]=1;
					k--;

				}
				else
				{
					c[j]=1;
					j++;
					k--;
					i++;

				}
			}
		}
		int cnt=0;
		for(i=0;i<n;i++)
		{
			if(d[i]==1)
			{
				cnt=cnt+1;
			}
		}
		cout<<cnt<<" ";
		memset(c,0,sizeof(c));
		 k=0;
		 cnt=0;
		for(i=0;i<n;i++)
		{
			if(c[n-1]==1)
				break;
			for(j=k;j<n;j++)
			{
				if(a[i]<b[j])
				{
					c[j]=1;
					k=j+1;
					break;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			if(c[i]==0)
			{
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}