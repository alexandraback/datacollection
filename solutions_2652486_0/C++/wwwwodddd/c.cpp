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
int a[300],p[300];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int t,r,n,m,k;
	cin>>t;
	cout<<"Case #1:"<<endl;
	for(int q=1;q<=t;q++)
	{
		cin>>r>>n>>m>>k;
		for(;r--;)
		{
			int ans=-1,zx,zy,zz;
			for(int j=1;j<=k;j++)
				cin>>a[j];
			for(int x=2;x<=5;x++)
				for(int y=2;y<=5;y++)
					for(int z=2;z<=5;z++)
					{
						if(x==3&&y==3&&z==4)
							x=3;
						memset(p,0,sizeof p);
						p[1]++;
						p[x]++;
						p[y]++;
						p[x*y]++;
						p[z]++;
						p[x*z]++;
						p[y*z]++;
						p[x*y*z]++;
						int r=1;
						for(int j=1;j<=k;j++)
							r*=p[a[j]];
						if(r>ans)
						{
							ans=r;
							zx=x;
							zy=y;
							zz=z;
						}
					}
			cout << zx << zy << zz << endl;
		}
	}
	return 0; 
}
