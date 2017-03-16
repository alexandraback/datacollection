#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;
vector<bool> in;
vector<bool> vis;
vector<vector<int> > ad;
int n;
void init()
{
    scanf("%d",&n);
    ad.assign(n+1,vector<int>());
    in.assign(n+1,true);
    int x,y;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d",&x);
        for(int j = 0; j < x; j++)
        {
            scanf("%d",&y);
            ad[i].push_back(y);
            in[y] = false;
        }
    }
}
bool search2(int x)
{
	int i,y;
    if(vis[x]) return true;
    vis[x] = true;
    for(i = 0; i < ad[x].size(); i++)
    {
        y = ad[x][i];
        if(search2(y)) 
        	return true;
    }
    return false;
}
bool search()
{
	int i;
    for(i = 1; i <= n; i++)
    {
        if(in[i])
        {
            vis.assign(n+1,false);
            if(search2(i))
                    return true;
        }
    }
    return false;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,casnum;    
    scanf("%d",&t);
    casnum = 0;
    while(t--)
    {
    	init();
        printf("Case #%d: ",++casnum);
        if(search()) 
        	printf("Yes\n");
        else 
        	printf("No\n");
    }
	return 0;
}

