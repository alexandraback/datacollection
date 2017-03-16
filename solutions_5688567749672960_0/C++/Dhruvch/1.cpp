#include<iostream>
#include<cstdio>
using namespace std;
int length[1000005];
int rev(int x)
{
	int ret=0;
	while(x)
	{
		ret=ret*10+x%10;
		x=x/10;
	}
	return ret;
}
void precomp()
{
	memset(length,1000000,sizeof(length));
	length[1]=1;
	for(int i=1;i<=1000000;i++)
	{
		int temp=rev(i);
		length[i+1]=min(length[i+1],length[i]+1);
		length[temp]=min(length[temp],length[i]+1);
	}
}
int main()
{
	int t;
	precomp();
	freopen ("input.in","r",stdin);
	freopen ("output.txt","w",stdout);
	cin>>t;
	long long x;
	int k=0;
	while(t--)
	{
		cin>>x;
		k++;
		cout<<"Case #"<<k<<": ";
		cout<<length[x]<<"\n";
	}
	return 0;
}