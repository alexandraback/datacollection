#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
int recycle(int a,int b)
{
		vector<int> v1,v2;
		while(a!=0)
		{
			v1.pb(a%10);
			a/=10;
		}
		while(b!=0)
		{		
			v2.pb(b%10);
			b/=10;
		}	
		reverse(v1.begin(),v1.end());
		reverse(v2.begin(),v2.end());
		int x=v1.size(),y=v2.size();
		if(x!=y)return 0;

		for(int i=0;i<x;i++)
		{
			vector<int> c;
			for(int j=i;j<x;j++)c.pb(v1[j]);
			for(int j=0;j<i;j++)c.pb(v1[j]);

			int res=1;
			for(int j=0;j<x;j++)
			if(c[j]!=v2[j]){res=0;break;}

			if(res)return 1;
		}

		return 0;	
}
int main()
{
	vector< pair<int,int> > v;

	for(int a=1;a<=1000;a++)
		for(int b=a+1;b<=1000;b++)
			if(recycle(a,b))
				v.push_back(make_pair(a,b));


	/*for(int i=0;i<(int)v.size();i++)
		cout<<v[i].first<<","<<v[i].second<<","*/

	int t;	
	scanf("%d",&t);

	for(int tt=1;tt<=t;tt++)
	{
		int A,B,res=0;
		scanf("%d %d",&A,&B);

		for(int i=0;i<(int)v.size();i++)
			if(v[i].first>=A and v[i].second<=B)res++;

		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}
