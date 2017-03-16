#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define mod 1000000007LL
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    int c=1,i,j,k,l,n,m,t,ans,r,c1,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&r,&c1,&w);
        j=c1/w;
        if(w==1)
            ans=(j*r)+1;
        else
            ans=((j)*r)+w;
        if(c1%w==0)
            ans--;
        printf("Case #%d: %d\n",c,ans);
        c++;
    }
    return 0;
}

