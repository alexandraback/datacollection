#if 1
#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;
int a[1005000]={};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<"Case #"<<t+1<<": "<<m<<endl;
			continue;
		}
		sort(a,a+m);
		int p=m,s=0;
		for(int i=0;i<m;i++)
		{
			while(a[i]>=n)
			{
				n+=n-1;
				s++;
			}
			n+=a[i];
			p=min(p,s+m-i-1);
		}
		cout<<"Case #"<<t+1<<": "<<p<<endl;
	}
	return 0;
}









#endif