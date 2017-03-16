#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
string s[105];
long long n,ans;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,i,j,l;
	cin>>t;
	for(l=1;l<=t;l++)
	{
		int n,m,k,temp;
		cout<<"Case #"<<l<<": ";
		cin>>n>>m>>k;
		if(n<m)
			temp=m,m=n,n=temp;
		if(n==1)
			cout<<2<<endl;
		else if(n==2)
			cout<<n<<endl;
		else
		{	
			int mini=k;
			for(i=3;i<=n;i++)
			{
				mini=min(mini,(i-2)*2+((k-(i-2)*2)/i)*2+(k-(i-2)*2)%i);
			}
			cout<<mini<<endl;
		}
	}
	return 0;
}