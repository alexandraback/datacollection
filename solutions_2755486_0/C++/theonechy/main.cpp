#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <sstream>
#include <algorithm>
using namespace std;
#define ll long long
const long long LINF = ~(((long long)0x1)<<63)/2;
const int INF=0X3F3F3F3F;
const double eps=1e-7;
int len[1000];
struct Node
{
    int day;
    int a,b;
    int s;
    bool operator <(const Node & t) const
    {
        return day<t.day;
    }
};
vector<Node> t;
int solve(int l,int r)
{
    int value=0;
    int ans=0;
   // cout<<l<<" "<<r<<" !!"<<" "<<endl;
    for(int i=l;i<=r;i++)
    {
        value=max(value,t[i].s);
        for(int j=t[i].a;j<=t[i].b;j++)
            if(len[j]<t[i].s)
            {
                ans++;
                break;
            }
    }
    for(int i=l;i<=r;i++)
    {
        value=max(value,t[i].s);
        for(int j=t[i].a;j<=t[i].b;j++)
            if(len[j]<t[i].s)
            {
                len[j]=t[i].s;
            }
    }
  //  cout<<ans<<endl;
    return ans;
}
int main()
{
    int T;
    freopen("C-small-attempt0.in.txt","r",stdin);
    freopen("C-small-attempt0.out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int N;
        scanf("%d",&N);
        t.clear();
        memset(len,0,sizeof(len));
        for(int i=0;i<N;i++)
        {
            int d,n,w,e,s,dd,dp,ds;
            scanf("%d%d%d%d",&d,&n,&w,&e);
            scanf("%d%d%d%d",&s,&dd,&dp,&ds);
            e-=1;
            for(int j=0;j<n;j++)
            {
                Node p;
                p.day=d;
                p.a=w+300;
                p.b=e+300;
                p.s=s;
                d+=dd;
                w+=dp;
                e+=dp;
                s+=ds;
                t.push_back(p);
            }
        }
        sort(t.begin(),t.end());
       // cout<<t.size()<<endl;
        int pre=0;
        int ans=0;
        for(int i=0;i<t.size();i++)
            if(i!=0&&t[i].day!=t[i-1].day)
            {
               // cout<<"!!!"<<endl;
                ans+=solve(pre,i-1);
                pre=i;
            }
        //cout<<"!!!!"<<endl;
        if(t.size()>pre)
        {
            ans+=solve(pre,t.size()-1);
        }
       // cout<<ans<<endl;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}





