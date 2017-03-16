#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int f[120][120];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	int T,E,R,n;
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		cin>>E>>R>>n;
		memset(f,0xc0,sizeof f);
		f[0][E]=0;
		for(int i=0;i<n;i++)
		{
			int v;
			cin>>v;
			for(int e=0;e<=E;e++)
				for(int x=0;x<=e;x++)
					f[i+1][min(e-x+R,E)]=max(f[i+1][min(e-x+R,E)],f[i][e]+x*v);
		}
		int z=0;
		for(int i=0;i<=E;i++)
			z=max(z,f[n][i]);
		cout << "Case #" << k << ": " << z << endl;
	}
	return 0; 
}
