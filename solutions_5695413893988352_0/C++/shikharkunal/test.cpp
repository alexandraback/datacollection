#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	for(ll cases=1;cases<=t;cases++)
	{
		printf("Case #%lld: ",cases);
		int greater=0; //0 =equal
		
		string c,j;
		cin>>c>>j;
		int i=0;
		while(c[i]=='?'&&j[i]=='?'&&i<c.length())
			{c[i]=j[i]='0';i++;}
		while((c[i]=='?'&&j[i]!='?')||(c[i]!='?'&&j[i]=='?')&&i<c.length())
		{
			if(c[i]!='?')
				j[i]=c[i];
			else c[i]=j[i];
			i++;
		}
		while(i<c.length())
		{
		if(c[i]=='?'&&j[i]=='?')
		{
			if(greater==0)
				c[i]=j[i]='0';   //check further pehle
			else if(greater==1)
			{
				c[i]='0';
				j[i]='9';
			}
			else
			{
				c[i]='9';
				j[i]='0';
			}
			
		}
		else if((c[i]=='?'&&j[i]!='?')||(c[i]!='?'&&j[i]=='?'))
		{
			if(greater==0)  //check further
			{
				if(c[i]=='?')
				c[i]=j[i];
			    else j[i]=c[i];
			}
			else if(greater==1)
			{
				if(c[i]=='?')
				  c[i]='0';
				else j[i]='9';
			}
			else
			{
				if(c[i]=='?')
				  c[i]='9';
				else j[i]='0';
			}
		}
		else
		{
			if(greater==0)
			{
				if(c[i]>j[i])
					greater=1;
				else if(j[i]>c[i])
					greater=2;
			}
		

		}
		i++;
	}
		
		cout<<c<<" "<<j<<endl;


	
	}
	return 0;
}