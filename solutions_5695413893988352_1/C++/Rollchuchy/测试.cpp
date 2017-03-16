/*
name:Rollchuchy
type:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	for(int kk=1;kk<=T;kk++)
	{
		char a[20],b[20];
		char c[20],d[20];
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d)); 
		cin>>a>>b;
		for(int i=0;i<strlen(a);i++)
		{
			if(a[i]!='?'&&b[i]!='?')
			{
				c[i]=a[i];d[i]=b[i];
				continue;
			}
			if(a[i]=='?'&&b[i]=='?'&&i==0)
			{
				c[i]='0';d[i]='0';
				continue;
			}
			if(a[i]!='?'&&b[i]=='?')
			{
				c[i]=a[i];
				d[i]=a[i];
				continue;
			}
			if(b[i]!='?'&&a[i]=='?')
			{
				c[i]=b[i];
				d[i]=b[i];
				continue;
			}
			if(a[i]=='?'&&b[i]=='?'&&i!=0)
			{
				if(c[i-1]>d[i-1])
				{
					c[i]='0';d[i]='9';
					continue;
				}
				else if(c[i-1]<d[i-1])
				{
					c[i]='9';d[i]='0';
					continue;
				}
				else if(c[i-1]==d[i-1])
				{
					c[i]='0';d[i]='0';
					continue;
				}
			}
		}
		cout<<"Case #"<<kk<<": ";
		cout<<c<<" "<<d<<endl;		
	}
	return 0;
}
