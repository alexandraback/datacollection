#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    freopen("1inp.in","r",stdin);
    freopen("1out.txt","w",stdout);
    int t,i,T,r,c,w,ans;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&r,&c,&w);
        ans=c/w;
        if(w==1)
            ans=(ans*r)+1;
        else
            ans=(ans*r)+w;
        if(c%w==0)
            ans--;
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}


