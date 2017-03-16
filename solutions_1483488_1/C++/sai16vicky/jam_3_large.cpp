#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
map< pair<int,int>,int > f;
map< pair<int,int>,int >::iterator it;
int main()
{
	vector< pair<int,int> > res;
	vector< pair<int,int> >::iterator it1,it2;

	for(int n=1;n<=2000000;n++)
	{
		int c=n;
		vector<int> v;
		while(c!=0)
		{
			v.push_back(c%10);
			c/=10;
		}
		reverse(v.begin(),v.end());
		int x=v.size();
		for(int i=0;i<x;i++)
		{
			vector<int> chk;	
			int sum=0;
			for(int j=i+1;j<x;j++)
			{
				sum*=10;
				sum+=v[j];
				chk.push_back(v[j]);
			}
			
			for(int j=0;j<=i;j++)
			{
				sum*=10;
				sum+=v[j];
				chk.push_back(v[j]);
			}

			if(chk[0]!=0 and sum<n and f.find(make_pair(n,sum))==f.end())
			{
				f[make_pair(sum,n)]+=1;
				res.push_back(make_pair(sum,n));
			}
		}
	}

	/*for(it=f.begin();it!=f.end();it++)
		if(it->first.first>=1111 and it->first.first<=2222 and it->first.second>=1111 and it->first.second<=2222 )
		{
			//cout<<it->first.first<<" "<<it->first.second<<", ";
			cnt++;
		}*/

	int t;
	scanf("%d",&t);


	for(int tt=1;tt<=t;tt++)
	{
		int A,B,res=0;
		scanf("%d %d",&A,&B);

		/*it1=lower_bound(res.begin(),res.end(),make_pair(A,B));	
		it2=upper_bound(res.begin(),res.end(),make_pair(B,B));
		cout<<abs((int)(it2-res.begin())-(int)(it1-res.begin()))<<"\n";*/

		 for(it=f.begin();it!=f.end();it++)
                if(it->first.first>=A and it->first.first<=B and it->first.second>=A and it->first.second<=B )res++;

		printf("Case #%d: %d\n",tt,res);
	}
	return 0;
}
