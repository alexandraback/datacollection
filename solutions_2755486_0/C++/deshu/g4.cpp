#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("c11.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++)
	{
		int N;
		cin>>N;
		vector<pair<int, pair<int,pair<int,int> > > > mahan;
		int d[N],n[N],w[N],e[N],s[N],dd[N],dp[N],ds[N];
		for(int i=0;i<N;i++)
		{
			scanf("%d%d%d%d%d%d%d%d",&d[i],&n[i],&w[i],&e[i],&s[i],&dd[i],&dp[i],&ds[i]);
			int range = e[i] - w[i];
			for(int j=0;j<n[i];j++)
			{
				//cout<<d[i]+i*dd[i]<<endl;
				mahan.push_back(make_pair(d[i]+j*dd[i],make_pair(s[i] + j*ds[i], make_pair(2*(e[i] + j*dp[i] - range + 500) , 2*(e[i] + j*dp[i] + 500)))) );
			}
		}
		sort(mahan.begin(),mahan.end());
		/*for(int i=0;i<6;i++)
		{
			cout<<mahan[i].first<<" ";			
			cout<<mahan[i].second.first<<" ";			
		    cout<<mahan[i].second.second.first<<" ";			
		    cout<<mahan[i].second.second.second<<endl;			
		
		
		}*/
	   int height[10000] = {0};
   	   int ll = mahan.size();
       long long ans = 0;
	   for(int xx = 0 ;xx<ll;xx++)
       {
          int r1 = mahan[xx].second.second.first;
		  int r2 = mahan[xx].second.second.second;
		  int str = mahan[xx].second.first;   	
	      int flag = 0;
		  for(int yy = r1;yy<=r2;yy++)
		  {
		    if(height[yy]<str)
		    {
		    	flag = 1;
		    	height[yy]=str;	
    		}
		  }
		  if(flag == 1)ans++;
  		}	  
        printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}