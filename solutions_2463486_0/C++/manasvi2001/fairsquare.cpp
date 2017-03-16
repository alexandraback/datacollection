#include <bits/stdc++.h>
using namespace std;
int ispal(int n)
{
	string s="";
	int r;
	while(n!=0)
	{
		r=n%10;
		s.push_back(r+'0');
		n=n/10;
	}
	string s1="";
	int i,len=s.length();
	for(i=len-1;i>=0;i--)
	{
		s1+=s[i];
	}
	if(s==s1)
		return 1;
	return 0;
}
int main()
{
	int t,u;
	cin>>t;
	u=t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int i,j,c=0;
		for(i=a;i<=b;i++)
		{
			j=sqrt(i);
			if(j*j==i)
			{
				if(ispal(i))
				{
					if(ispal(j))
						c++;
				}
			}
		}
		cout<<"Case #"<<u-t<<": "<<c<<endl;
	}
	return 0;
}