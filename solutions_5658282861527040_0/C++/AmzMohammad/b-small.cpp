#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;
int a,b,k;
int main()
{

	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("B-small.out","w",stdout);
	
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++)
	{
		cin>>a>>b>>k;
		int res=0;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				int c= i&j;
				if(c<k)
					res++;
			}
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;

	}
	return 0;
}
