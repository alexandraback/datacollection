#include <bits/stdc++.h>
#define N 64

using namespace std;
int t;
long long int b,m;
int mat[N][N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>b>>m;
		long long int k = (1L<<(b-2));
		if(m>k)
		{
			cout<<"Case #"<<c<<": IMPOSSIBLE"<<endl;
		}
		else
		{
			cout<<"Case #"<<c<<": POSSIBLE"<<endl;
			for(int i=1;i<=b;++i)
				for(int j=1;j<=b;++j)
					mat[i][j]=0;
			for(int i=1;i<b;++i)
				for(int j=i+1;j<b;++j)
					mat[i][j]=1;
			mat[1][b]=1;
			m--;
			for(int i=0;i<b-2;++i)
			{
				long long int k = (1L<<i);
				if(k&m)
				{
					mat[i+2][b]=1;
				}
			}
			for(int i=1;i<=b;++i)
			{
				for(int j=1;j<=b;++j)
					cout<<mat[i][j];
				cout<<endl;
			}

		}
	}

	return 0;
}