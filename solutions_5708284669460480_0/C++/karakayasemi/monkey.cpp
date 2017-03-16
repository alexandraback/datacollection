#include <iostream>
#include <cstdio>
#include <string>
#include <limits>
int k,l,s,t;
using namespace std;

int checkp(string in)
{
	int last=in.length()-1;
	for(int i=in.length()-2;i>0;i--)
	{
		int control=0;
		for(int j=0;j<=i;j++)
		{
			if(in[i-j]!=in[last-j])
			{
				control=1;
				break;
			}
		}
		if(control==0)
			return i+1;
	}
	return 0;
}

long double probab(string let,string key)
{
	long double total=1;
	for(int i=0;i<let.length();i++)
	{
		long double count=0;
		for(int j=0;j<key.length();j++)
		{
			if(key[j]==let[i])
				count++;
		}
		total=total*(count/key.length());
	}
	return total;
}
int main()
{
	freopen("inp.in","r",stdin);
	freopen("outpux.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>k>>l>>s;
		string keys,letter;
		cin>>keys;
		cin>>letter;
		int pvalue=checkp(letter);
		int banana=0;
		long double prob=0;
		prob=probab(letter,keys);
		long double result=0;
		if(s>=l && prob>0)
		{
			banana=((s-l)/(l-pvalue))+1;
			result=banana-(banana*prob);
		}
		cout.precision(10);
		cout<<"Case #"<<i<<": "<<fixed<<result<<endl;
	}
	
}