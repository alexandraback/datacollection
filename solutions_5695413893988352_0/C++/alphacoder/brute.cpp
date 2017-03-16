#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a,b,c1,c2;
int m=99999;
string conv(int a,int len)
{
	string c,d;
	for(int i=0;i<len;i++)
	{
		c.push_back(a%10+'0');
		a/=10;
	}
	for(int i=len-1;i>=0;i--)
	{
		d.push_back(c[i]);
	}
	return d;

}
void sol(int l,int x,int y)
{
	if(l==a.length())
		{
			if(m>abs(x-y))
			{
				//cout<<x<<" "<<y<<endl;
				c1=conv(x,a.length());
				c2=conv(y,a.length());
				m=abs(x-y);
			}
			return ;
		}
	if(a[l]=='?'&&b[l]=='?')
		for(int i=0;i<=9;i++)
		{
			int cp=x;
			cp=cp*10+i;
			for(int j=0;j<=9;j++)
			{
				int co=y;
				co=co*10+j;
			    sol(l+1,cp,co);
		    }
		}
	else if(a[l]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			int cp=x;
			cp=cp*10+i;
			sol(l+1,cp,y*10+b[l]-'0');
		}
	}	
	else if(b[l]=='?')
	{
		for(int i=0;i<=9;i++)
		{
			int cp=y;
			cp=cp*10+i;
			sol(l+1,x*10+a[l]-'0',cp);
		}
	}
	else 
	{
		sol(l+1,x*10+a[l]-'0',y*10+b[l]-'0');
	}	
}
int main()
{
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		m=9999999;
		int maa=0,x,y;
		cin>>a>>b;
		sol(0,0,0);
		cout<<"Case #"<<j<<":"<<" "<<c1<<" "<<c2<<endl;
	}
}