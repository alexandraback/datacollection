#include<iostream>
using namespace std;
int lastd(int i)
{
	int j=i;
	while(j>0)
	{
		i=j%10;
		j=j/10;
	}
	return i;
}
int rever(int i)
{
	int t=0;
	while(i>0)
	{
		t=t*10+i%10;
		i=i/10;
	}
	return t;
}
int main()
{
	int ans[1000005];
	ans[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(i%10!=0&&rever(i)<i)
			ans[i]=1+min(ans[rever(i)],ans[i-1]);
		else
			ans[i]=ans[i-1]+1;
	//	cout<<i<<" : "<<ans[i]<<"\n";
	}
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		cout<<"Case #"<<i<<": "<<ans[n]<<"\n";
	}

	return 0;
}
