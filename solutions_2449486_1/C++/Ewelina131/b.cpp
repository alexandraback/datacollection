#include<iostream>
using namespace std;

int k[110], w[110], a[110][110];

int main()
{
	int p, n, m, t=0, x;
	cin>>p;
	while(t<p)
	{
		t++;
		cin>>n>>m;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin>>a[i][j];
				if(a[i][j]>k[i])
				k[i]=a[i][j];
				if(a[i][j]>w[j])
				w[j]=a[i][j];
			}
		}
		x=0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(a[i][j]!=w[j] && a[i][j]!=k[i])
				{
					x=1;
				}
			}
		}
		for(int i=0; i<m || i<n; i++)
		{
			k[i]=0;
			w[i]=0;
		}
		if(x)
		{
			cout<<"Case #"<<t<<": NO\n";
		}
		else
		{
			cout<<"Case #"<<t<<": YES\n";
		}
	}
	return 0;
}	
	
		
