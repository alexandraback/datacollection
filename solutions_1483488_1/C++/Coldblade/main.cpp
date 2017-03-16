#include<iostream>

using namespace std;

int main()
{
	int t, a, b, n, m;
	cin>>t;
	for( int i=0; i<t; i++)
	{
		int c=0;
		int d=1;
		int count=0;
		cin>>a>>b;
		for( int j=a/10; j; j/=10)
		{
			c+=1;
			d*=10;
		}
		for( n=a; n<b; n++)
		{
			m=n;
			for( int k=0; k<c; k++)
			{
				m=(m%10)*d+m/10;
				if(m==n)
					break;
				if(m>n && m<=b)
					count++;
			}
		}
		cout<<"Case #"<<i+1<<": "<<count<<'\n';
	}
}