#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    string s1,s2;
};
node p[1005];
int n;
bool check(int mask)
{
    map<string,bool>mp1,mp2;
    for(int i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            mp1[p[i].s1]=1;
            mp2[p[i].s2]=1;
        }
    }
    for(int i=0; i<n; i++)
    {
        if((mask&(1<<i))==0)
        {
            if(mp1[p[i].s1]==0)
                return false;
            if(mp2[p[i].s2]==0)
                return false;
        }
    }
    return true;
}
int cal(int mask)
{
    int ans=0;
    while(mask)
    {
        ans=ans+mask%2;
        mask/=2;
    }
    return ans;
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
////    freopen("A-large.in","r",stdin);
////    freopen("A-large.out","w",stdout);
    int T;
    cin >> T;
//    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> p[i].s1 >> p[i].s2;
        int ans=0;
        for(int i=1; i<(1<<n); i++)
        {
            if(check(i))
            {
                ans=max(ans,n-cal(i));
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
