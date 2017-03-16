#include<iostream>
#include<algorithm>
using namespace std;

int t[100], r[100], rk[100][100], z[100], p[1000000], ap[1000000];

int main()
{
	int t1, x, n, k, m, a;
	cin>>t1;
	for(int f=1; f<=t1; f++)
	{
		cin>>k>>n;
		m=0;
		for(int i=0; i<k; i++)
		{
			cin>>a;
			p[a]++;
			ap[a]++;
			if(m<a)
			m=a;
		}
		cout<<"Case #"<<f<<": ";
		for(int i=0; i<n; i++)
		{
			cin>>r[i]>>z[i];
			for(int j=0; j<z[i]; j++)
			{
				cin>>rk[i][j];
			}
		}
		for(int i=0; i<n; i++)
		{
			t[i]=i;
		}
		for(int i=0; i<(1<<(n+1)); i++)
		{
			x=0;
			//cout<<i<<"\n";
			for(int j=0; j<n; j++)
			{
				//cout<<t[j]<<" "<<r[t[j]]<<" "<<ap[r[t[j]]]<<"\n";
				if(ap[r[t[j]]])
				{
					ap[r[t[j]]]--;
					for(int g=0; g<z[t[j]]; g++)
					{
						ap[rk[t[j]][g]]++;
						if(rk[t[j]][g]>m)
						m=rk[t[j]][g];
					}
				}
				else
				{
					x=-1;
					break;
				}
				//cout<<t[j]<<" "<<r[t[j]]<<" "<<ap[r[t[j]]]<<"\n";
			}
			if(x==0)
			{
				for(int j=0; j<n; j++)
				{
					cout<<t[j]+1<<" ";
				}
				x=1;
				break;
			}
				for(int i=0; i<=m; i++)
				ap[i]=p[i];
			//cout<<"\n";
			next_permutation(t, t+n);
		}
		if(x!=1)
		{
			cout<<"IMPOSSIBLE";
		}
		for(int i=0; i<=m; i++)
		{
			p[i]=0;
			ap[i]=0;
		}
		cout<<"\n";
	}
	return 0;
}
				
		
