#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll po[100], out[100];
int a[100][100];

int main()
{
	ios_base::sync_with_stdio(false);
	int t,f,b;
	ll m;
	cin>>t;
	po[0]=1;
	for(int i=1;i<50;i++)
		po[i]=po[i-1]*2;
	for(int loop=1;loop<=t;loop++)
	{
		f=0;
		cin>>b>>m;
		for(int i=1;i<=b;i++)
		{
			for(int j=1;j<=b;j++)
				a[i][j]=0;
			out[i]=0;
		}
		cout<<"Case #"<<loop<<": ";
		if(m > po[b-2])
			cout<<"IMPOSSIBLE\n";
		else
		{
			out[1]=1;
			a[1][b]=1;
			m--;
			if(!m)
			{
				cout<<"POSSIBLE\n";
				for(int i=1;i<=b;i++)
				{
					for(int j=1;j<=b;j++)
						cout<<a[i][j];
					cout<<"\n";
				}
				f=1;
				continue;
			}
			for(int i=0;i<=b-2;i++)
			{
				for(int j=i+1;j>=1;j--)
				{
					if(out[j] <= m)
					{
						m-=out[j];
						out[i+2]+=out[j];
						a[j][i+2]=1;
						a[i+2][b]=1;
						if(!m)
						{
							cout<<"POSSIBLE\n";
							for(int i=1;i<=b;i++)
							{
								for(int j=1;j<=b;j++)
									cout<<a[i][j];
								cout<<"\n";
							}
							f=1;
							break;
						}
					}
				}
				if(f)
					break;
			}
		}
	}
	return 0;
}