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

int arr[1009];
int n;
int dp[1009][1009];
int f(int i, int maxi)
{
    if(i==n)
        return maxi;
    int ret=1e9;
    if(dp[i][maxi]!=-1)
        return dp[i][maxi];
    for(int f1=1;f1<=arr[i];f1++)
    {
        ret=min(ret,f1-1+f(i+1,max(maxi,(arr[i]+f1-1)/f1)));
    }
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
        memset(dp,-1,sizeof dp);
        for(int f=0;f<n;f++)
        {
            cin>>arr[f];
        }
        cout<<"Case #"<<tc<<": "<<f(0,0)<<endl;
    }
}
