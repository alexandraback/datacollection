#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,ans1,ans2,j,k;
	long double g[1001],b[1001];
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
			cin>>g[j];
		for(j=0;j<n;j++)
			cin>>b[j];
		sort(g,g+n);
		sort(b,b+n);
		j=k=0;
		ans1=0;
		while(j<n)
		{
			if(g[j]>b[k])
			{
				k++;ans1++;
			}
			j++;
		}
		ans2=0;
		j=k=0;
		while(k<n)
		{
			if(b[k]>g[j])
			{
				j++;ans2++;
			}
			k++;
		}
		ans2=n-ans2;
		cout<<"Case #"<<i<<": "<<ans1<<" "<<ans2<<endl;
	}
}