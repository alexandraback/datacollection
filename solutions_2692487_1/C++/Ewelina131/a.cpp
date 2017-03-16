#include<iostream>
#include<algorithm>
using namespace std;

int b[1000010];

int main()
{
	int m, a, t, n, d;
	cin>>t;
	for(int f=1; f<=t; f++)
	{
		cin>>a>>n;
		for(int i=0; i<n; i++)
		{
			cin>>b[i];
		}
		sort(b, b+n);
		d=0;
		m=n;
		for(int i=0; i<n; i++)
		{
			if(b[i]<a)
			{
				a+=b[i];
			}
			else
			{
				m=min(m, d+n-i);
				while(a<=b[i] && a!=1)
				{
					a+=a-1;
					d++;
				}
				if(a==1)
				{
					m=n;
					d=n;
					break;
				}
				a+=b[i];
			}
		}
		m=min(m, d);
		cout<<"Case #"<<f<<": "<<m<<"\n";
	}
	return 0;
}

				
