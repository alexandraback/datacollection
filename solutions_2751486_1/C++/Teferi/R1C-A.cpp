#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long LINT;

void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int n;
		string s;
		cin>>s>>n;

		LINT r=0;
		int beg=0;
		int cur=0;
		for(LINT i=0; i<s.length(); i++)
		{
			if(!(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'))
			{
				cur++;
				if(cur>=n)
				{
					LINT bb=i-n+1;
					r+= (bb-beg+1) * (s.length()-i);
					beg=bb+1;
				}
			}
			else
				cur=0;
		}
	
	cout<<"Case #"<<ii+1<<": "<<r<<endl;
	}
}



/*
void main()
{
	int t;
	cin>>t;
	for(int ii=0; ii<t; ii++)
	{
		int n;
		string s;
		cin>>s>>n;

		int r=0;
		for(int i=0; i<s.length(); i++)
			for(int j=i; j<s.length(); j++)
			{
				int cur=0;
				int maxn=0;
				for(int k=i; k<=j; k++)
				{
					if(!(s[k]=='a' || s[k]=='e' || s[k]=='i' || s[k]=='o' || s[k]=='u'))
					{
						cur++;
						maxn=max(maxn,cur);
					}
					else 
						cur=0;
				}
				if(maxn>=n)
				{
					r++;
				}
			}
	
	cout<<"Case #"<<ii+1<<": "<<r<<endl;
	}
}
*/