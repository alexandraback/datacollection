//
//  p1.cpp
//
//
//  Created by Mac on 4/3/15.
//
//

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#define INF 2147483646
#define MAX_D 1005
using namespace std;

int D,P[MAX_D],ans;
struct pan
{
    vector<int> pancake;
};

int dfs(int d,int w,pan now)
{
    sort(now.pancake.begin(),now.pancake.end());
    if(now.pancake[now.pancake.size()-1]==1)return 1+d;
    pan tmp;
    int res=INF;
    if(w==0)
    {
        for(int i=0;i<now.pancake.size();i++)
        {
            if(now.pancake[i]!=1)
            {
                tmp.pancake.push_back(now.pancake[i]-1);
            }
        }
        res=min(res,min(dfs(d+1,0,tmp),dfs(d+1,1,tmp)));
    }
    else
    {
        int t=now.pancake[now.pancake.size()-1];
        
        for(int j=t/4+1;j<=t/2;j++){
            pan tmp1;
            for(int i=0;i<now.pancake.size()-1;i++)
            {
                tmp1.pancake.push_back(now.pancake[i]);
            }
        
            tmp1.pancake.push_back(j);
            tmp1.pancake.push_back(t-j);
            res=min(res,min(dfs(d+1,0,tmp1),dfs(d+1,1,tmp1)));
        }
    }
    return res;
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("p2.out","w",stdout);
    int T;
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
        pan Pan;
		cin>>D;
		ans=INF;
        
        for(int i=0;i<D;i++){cin>>P[i];Pan.pancake.push_back(P[i]);}
        
        ans=min(dfs(0,0,Pan),dfs(0,1,Pan));
        
		cout<<"Case #"<<kase<<": "<<ans<<endl;
	}
}
