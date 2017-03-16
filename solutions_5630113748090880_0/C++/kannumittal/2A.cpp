#include<bits/stdc++.h>
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
using namespace std;
int main()
{
	
	f_in("2asmall.in");
	f_out("2asmallout.txt")
	long long t,i,j,n,k,m;
	cin>>t;
	k=0;
	while(t--)
	{
		k++;
		cin>>n;
		
		int h[2503]={0};
		for(i=0;i<2*n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>m;
				h[m]++;
			}
		}
		int a[60];
		j=0;
		for(i=0;i<=2500;i++)
		{
			if(h[i]%2!=0)
			{
				a[j]=i;
				j++;
			}
		}
		sort(a,a+j);
		cout<<"Case #"<<k<<": ";
		for(i=0;i<j;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
