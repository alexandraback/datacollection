#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct complex1
{
	char result;
	int sign;
};
complex1 multiply(char x,char y)
{
	complex1 c;
	if(x=='1' && y=='1')
	{
		c.result='1';
		c.sign=1;
	}
	else if(x=='1' && y=='i')
	{
		c.result='i';
		c.sign=1;
	}
	else if(x=='1' && y=='j')
	{
		c.result='j';
		c.sign=1;
	}
	else if(x=='1' && y=='k')
	{
		c.result='k';
		c.sign=1;
	}


	else if(x=='i' && y=='1')
	{
		c.result='i';
		c.sign=1;
	}
	else if(x=='i' && y=='i')
	{
		c.result='1';
		c.sign=-1;
	}
	else if(x=='i' && y=='j')
	{
		c.result='k';
		c.sign=1;
	}
	else if(x=='i' && y=='k')
	{
		c.result='j';
		c.sign=-1;
	}


	else if(x=='j' && y=='1')
	{
		c.result='j';
		c.sign=1;
	}
	else if(x=='j' && y=='i')
	{
		c.result='k';
		c.sign=-1;
	}
	else if(x=='j' && y=='j')
	{
		c.result='1';
		c.sign=-1;
	}
	else if(x=='j' && y=='k')
	{
		c.result='i';
		c.sign=1;
	}


	else if(x=='k' && y=='1')
	{
		c.result='k';
		c.sign=1;
	}
	else if(x=='k' && y=='i')
	{
		c.result='j';
		c.sign=1;
	}
	else if(x=='k' && y=='j')
	{
		c.result='i';
		c.sign=-1;
	}
	else if(x=='k' && y=='k')
	{
		c.result='1';
		c.sign=-1;
	}
	return c;
}
complex1 compute(string s)
{
	complex1 ans=multiply(s[0],s[1]);
	int neg=0;
	if(ans.sign==-1)
		neg++;
	for(int i=2;i<s.length();i++)
	{
		ans=multiply(s[i],ans.result);
		if(ans.sign==-1)
			neg++;
	}
	complex1 ret;
	ret.result=ans.result;
	if(neg%2==1)
		ret.sign=-1;
	else
		ret.sign=1;
	return ret;
}

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	for(int i1=1;i1<=t;i1++)
	{
		int l,x;
		cin>>l>>x;
		string s,s1;
		cin>>s1;
		s=s1;

		for(int i=1;i<x;i++)
			s+=s1;
		//cout<<s<<endl;
		int n=s.length();
		bool flag=false;
		complex1 ans;
		ans.result='1';
		ans.sign=1;
		int neg=0;
		for(int i=0;i<n;i++)
		{
			ans=multiply(ans.result,s[i]);
			//cout<<ans.result<<" "<<ans.sign<<" ";
			if(ans.sign==-1)
				neg++;
		}
		//cout<<neg%2<<ans.result<<endl;
		if(ans.result!='1' || neg%2!=1)
			cout<<"Case #"<<i1<<": NO"<<endl;
		else
		{
			complex1 ir;
			complex1 kr;
			ir.result='1';
			ir.sign=1;
			bool flagi=false;
			bool flagk=false;
			int i;
			neg=0;
			for(i=0;i<n;i++)
			{
				ir=multiply(ir.result,s[i]);
				if(ir.sign==-1)
					neg++;
				//cout<<ir.result<<endl;
				if(ir.result=='i' && neg%2==0)
				{
					flagi=true;
					break;
				}
			}
			//cout<<"out1"<<flagi<<endl;

			kr.result='1';
			kr.sign=1;
			neg=0;
			for(int j=n-1;j>i;j--)
			{
				kr=multiply(kr.result,s[j]);
				if(ir.sign==-1)
					neg++;
				if(kr.result=='k' && neg%2==0)
				{
					flagk=true;
					break;
				}
			}
			//cout<<"out2"<<flagk<<endl;
			if(flagi && flagk)
				cout<<"Case #"<<i1<<": YES"<<endl;
			else
				cout<<"Case #"<<i1<<": NO"<<endl;
		}
	}
	return 0;
}
