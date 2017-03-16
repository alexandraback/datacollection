#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


long long n,i,j,k,q,s,w,v,pat,pos,sum;//long long
string t;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>v;w=v;
	while(v--)
	{
		cin>>t;
		cin>>n;
		pos=-1;sum=0;
		for(i=0;i<t.length();i++)
		{
			if(t[i]!='a' && t[i]!='i' && t[i]!='o' && t[i]!='u' && t[i]!='e')
			{
				if(i==0)
				{
					sum=1;
				}
				else
				{
					sum++;
				}
				if(sum>=n)
				{
					pos=i-n+1;
					q+=pos+1;
				}
				else
				{
					if(pos!=-1)
					{
						q+=pos+1;
					}
				}
			}
			else
			{
				sum=0;
				if(pos!=-1)
				{
					q+=pos+1;
				}
			}
		}
		cout<<"Case #"<<w-v<<": "<<q<<endl;
		q=0;
	}
	return 0;
}

