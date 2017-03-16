#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,n,i,j,k,l;
	string a[105],b[105];
	cin>>t;
	for(l=1;l<=t;l++)
	{
		int a,b,c,ans=0;
		cout<<"Case #"<<l<<": ";
		cin>>a>>b>>c;
		for(i=0;i<a;i++)
		{
			for(j=0;j<b;j++)
			{
				if((i&j)<c)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}