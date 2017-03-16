#include<bits/stdc++.h>
using namespace std;
int n=4;
vector<string> v,vec;
void make(int i,string s)
{
	if(i==n)
	{
		cout<<s<<endl;
		v.push_back(s);
		return;
	}
	make(i+1,s+'L');
	make(i+1,s+'G');
}
void another(string k,string s,int i)
{
	if(i==s.length())
	{
		cout<<k<<endl;
		vec.push_back(k);
		return ;
	}
	if(s[i]=='L')
	{
		k+=s;
		another(k,s,i+1);
	}
	else
	{
		for(int j=0;j<s.length();j++)
		k+='G';
		another(k,s,i+1);
	}
}
int main()
{
	make(0,"");
	for(int i=0;i<v.size();i++)
	another("",v[i],0),v[i]=vec[i];
//	vec.clear();
//	for(int i=0;i<v.size();i++)
//	another("",v[i],0);
	for(int i=0;i<16;i++)
	{
		for(int j=i+1;j<16;j++)
		{
			//for(int l=j+1;l<125;l++)
			{
				bool fl=0;
				for(int k=1;k<vec.size();k++)
				{
					if(vec[k][i]=='L'&&vec[k][j]=='L')//&&vec[k][l]=='L')
					fl=1;
				}
				if(fl==0)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}	
			}
		}
	}
}
