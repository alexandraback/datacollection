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

int arr[120][60];
bool vis[120];
int n;

vector<int>ans;

void sol(int x)
{
    int c=1e9,d=0,i,j;
    for(int f=0;f<2*n-1;f++)
    {
        if(!vis[f])
        {
            if(arr[f][x]<c)
                c=arr[f][x],d=1,i=f;
            else if(arr[f][x]==c)
                d++,j=f;
        }
    }
    if(d==1)
    {
        multiset<int>ss;
        for(int f=0;f<2*n-1;f++)
            if(!vis[f])
                ss.insert(arr[f][x]);
        for(int f=x+1;f<n;f++)
            ss.erase(ss.find(arr[i][f]));
        multiset<int>::iterator it;
        for(it=ss.begin();it!=ss.end();it++)
            ans.push_back(*it);
    }
    else
    {
        multiset<int>ss;
        for(int f=x;f<n;f++)
            ss.insert(arr[i][f]);
        for(int f=x;f<n;f++)
            ss.insert(arr[j][f]);
        for(int f=0;f<2*n-1;f++)
            if(!vis[f])
                ss.erase(ss.find(arr[f][x]));
        multiset<int>::iterator it;
        for(it=ss.begin();it!=ss.end();it++)
            ans.push_back(*it);
        vis[i]=vis[j]=1;
        sol(x+1);
    }
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
        for(int f=0;f<2*n-1;f++)
            for(int f1=0;f1<n;f1++)
                cin>>arr[f][f1];
        ans.clear();
        memset(vis,0,sizeof vis);
        sol(0);
        cout<<"Case #"<<tc<<":";
        for(int f=0;f<ans.size();f++)
            cout<<" "<<ans[f];
        cout<<endl;
    }
    return 0;
}
