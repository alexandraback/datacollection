/*
Try Try & Try until you solve the problem...
Nothing is impossible for the problem solvers... :)
*/
/*

*/
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <numeric>

#include <cmath>
#include <cstdio>

#define IP(n) for(i=0;i<n;i++)
#define JP(n) for(j=0;j<n;j++)
#define KP(n) for(k=0;k<n;k++)

#define vi vector<int>
#define vi2 vector<vector<int>>
#define vs vector<string>

#define pb push_back
#define TC int t,check=1;cin>>t;while(check<=t)
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define ms(x,a) memset(x,a,sizeof(x))
#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)

using namespace std;

int val[105],n,a;

int dp[105][1000005];

int calc(int in,int tot)
{
    if(tot>1000000) return 0;

    if(in==n) return 0;

    if(dp[in][tot]!=-1) return dp[in][tot];

    int ret=0;

    if(tot>val[in])
    {
        ret=calc(in+1,tot+val[in]);
    }
    else
    {
        ret=1+min(calc(in,2*tot-1),calc(in+1,tot));
    }

    dp[in][tot]=ret;

    return ret;
}

int main()
{
    //read("As.in");
    //write("As.txt");

    int t,check=1;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&a,&n);

        for(int i=0;i<n;i++)
        scanf("%d",&val[i]);

        int ans=0;

        if(a==1)
        {
            ans=n;
        }
        else
        {
            sort(val,val+n);
            ms(dp,-1);
            ans=calc(0,a);
        }
        printf("Case #%d: %d\n",check++,ans);
    }

    return 0;
}
