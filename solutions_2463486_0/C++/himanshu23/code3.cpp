#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
//	freopen("C.in","r",stdin);
//	freopen("outputC.in","w",stdout);
	int a[1001]={0};
	for(int i=0;i<1001;i++)
	{
		int num=i;
		int sum=0;
		while(num>0)
		{
			int r=num%10;
			sum=sum*10+r;
			num=num/10;
		}
		if(sum==i)
		a[i]=1;
		
		
	}
	int b[1001]={0};
	for(int i=0;i*i<1001;i++)
	{
		b[i*i]=i;
	}
	int c[1001]={0};
	for(int i=0;i<=1000;i++)
	{
		if(b[i]>0)
		{
		//	cout<<a[i]<<" "<<a[b[i]]<<endl;
			if(a[i]&&a[b[i]])
			c[i]=1;
		}
	}
	int t;
	cin>>t;
	int w=0;
	while(t--)
	{
		w++;
		int p,q;
		cin>>p>>q;
		int cnt=0;
		for(int i=p;i<=q;i++)
		if(c[i])
		cnt++;
		
		cout<<"Case #"<<w<<": "<<cnt<<endl;
	}
	return 0;
	
}
