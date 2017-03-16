#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long LINT;

int tbl[1000][1000];

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