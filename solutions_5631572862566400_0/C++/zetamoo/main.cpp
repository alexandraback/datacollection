#include <vector>
#include <list>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int n,arr[15];
bool vis[15]={0};

int dfs(int i,int prev,int start)
{
    if(arr[i]==prev)
    {
        int ret=1;
        for(int f=1;f<=n;f++)
            if(!vis[f])
            {
                vis[f]=1;
                ret=max(ret,1+dfs(f,i,start));
                vis[f]=0;
            }
        return ret;
    }
    if(arr[i]==start)
        return 1;
    if(vis[arr[i]])
        return -1e9;
    vis[arr[i]]=1;
    int ret= dfs(arr[i],i,start)+1;
    vis[arr[i]]=0;
    return ret;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        cin>>n;
        for(int f=1;f<=n;f++)
            cin>>arr[f];
        cout<<"Case #"<<tc<<": ";
        int ans=0;
        for(int f=1;f<=n;f++){
            vis[f]=1;
            ans=max(ans,dfs(f,f,f));
            //cout<<ans<<" "<<f<<endl;
            vis[f]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
