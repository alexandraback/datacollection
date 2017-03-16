#include<bits/stdc++.h>
using namespace std;
int a[2000000];
int reverse(int n)
{
	int temp=0;
	while(n!=0)
	{
		temp*=10;
		temp+=n%10;
		n/=10;
	}
	return temp;
}
int main()
{
	int i;
	a[1]=1;
	for(i=2;i<=1000000;i++)
	{
		int temp=reverse(i);
		if(temp<i && reverse(temp)==i)
		{
			a[i]=min(a[temp]+1,a[i-1]+1);
		}
		else a[i]=a[i-1]+1;
	}
	int t,n;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Case #"<<i<<": "<<a[n]<<endl;
	}
}
