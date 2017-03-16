#include<iostream>
using namespace std;
long long a[1000010], k[100][100];

int main()
{
	long long n, x, y, g, d, s;
	int t;
	cin>>t;
	a[0]=1;
	for(int i=1; i<=100000; i++)
	{
		a[i]=a[i-1]+i*4+1;
		if(a[i]>1000000)
		{
			i++;
			while(i<100000)
			{
				a[i]=a[i-1];
				i++;
			}
		}
	//	cout<<i<<" "<<a[i]<<"\n";
	}
	
	for(int i=0; i<=22; i++)
	k[i][0]=1;
	for(int i=1; i<22; i++)
	{
		for(int j=1; j<=22; j++)
		{
			k[i][j]=k[i-1][j]+k[i-1][j-1];
		}
	}
	for(int f=1; f<=t; f++)
	{
		cin>>n>>x>>y;
		if(x<0)
		x*=-1;
		if(y<0)
		y*=-1;
		s=x+y;
		if(s%2)
		{
			cout<<"Case #"<<f<<": "<<"0.0\n";
		}
		else
		{
			s/=2;
			if(s==0)
			{
				cout<<"Case #"<<f<<": "<<"1.0\n";
			}
			else
			{
				n-=a[s-1];
				g=0;
				d=0;
				if(n<=0)
				{
					cout<<"Case #"<<f<<": "<<"0.0\n";
				}
				else
				{
					for(int i=0; i<=n; i++)
					{
						if(i<s*2+1 && n-i<s*2+1)
						{	
							d+=k[n][i];
							if(i>=y+1)
							g+=k[n][i];
						}
					}
					double wyn;
					wyn=(double)(g)/(double)(d);
					if(g==d)
					cout<<"Case #"<<f<<": "<<"1.0\n";
					else
					if(g==0)
					cout<<"Case #"<<f<<": "<<"0.0\n";
					else
					cout<<"Case #"<<f<<": "<<wyn<<"\n";
				}
			}
		}
	}		
	return 0;
}	
