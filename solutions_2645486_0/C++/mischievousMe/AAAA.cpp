#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> ii;
typedef vector<int> vi;

#define PI 3.1415926535897932385

int v[11];
int E,R,N;
int dp[11][15];

int func(int i,int energy)
{
    if(i==N) return 0;
    int ans=0;
    if(dp[i][energy]!=-1) return dp[i][energy];
    for(int j=0;j<=energy;j++)
        ans=max(ans,v[i]*j+func(i+1,min(energy-j+R,E)));
    return dp[i][energy]=ans;
}

int main()
{
    int t,x=0;
    //freopen("B1.in","r",stdin);
    //freopen("B1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        x++;
        memset(dp,-1,sizeof(dp));
        cin>>E>>R>>N;
        for(int i=0;i<N;i++)
            cin>>v[i];
        printf("Case #%d: %d\n",x,func(0,E));
    }
    return 0;
}
