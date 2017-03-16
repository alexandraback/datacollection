#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stdlib.h>
using namespace std;
int main()
{
	freopen("C:\\Users\\Tarun\\Desktop\\ip.txt","r",stdin);
	freopen("C:\\Users\\Tarun\\Desktop\\op.txt","w",stdout);
	int t,i,j,k,l,m;
	cin>>t;
	for(l=1;l<=t;l++)
	{
		long long p,q,flag=0,temp;
		string s;
		cout<<"Case #"<<l<<": ";
		cin>>s;
		p=0;
		for(i=0;i<s.size()&&s[i]>='0' && s[i]<='9';i++)
		{
			p=p*10+s[i]-'0';
		}
		q=0;i++;
		for(;i<s.size();i++)
		{
			q=q*10+s[i]-'0';
		}
		if(p>q)
		{
			flag=1;
		}
temp=__gcd(p,q);
p=p/temp;
q=q/temp;
		temp=q;
		
		while(q>1)
		{
			if(q%2==0)
				q=q/2;
			else
			{
				flag=1;
				break;
			}
		}i=0;
		q=temp;
		while(p/q<1)
		{
			p=p*2;
			i++;
		}
		if(flag==0||i>40)
			cout<<i<<endl;
		else
			cout<<"impossible\n";
	}
	return 0;
}