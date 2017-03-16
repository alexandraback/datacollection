#include<cstdio>
#include<iostream>
#include <cstring>
using namespace std;
const int Maxn=110;
int data[Maxn];
int n,s,p;
int solve()
{
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&data[i]);
        int b=data[i]-p;
        if(b<0)continue;
        int c=b/2;
        if(c>=p-1)ans++;
        if(c==p-2&&s>0)
        {
            ans++;
            s--;
        }
    }
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas)
    {
        scanf("%d%d%d",&n,&s,&p);
        printf("Case #%d: %d\n",cas,solve());
    }
}
