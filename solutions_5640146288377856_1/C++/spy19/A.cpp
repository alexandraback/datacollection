#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1<<30
#define Mod 10000007
#define dbg printf("%c",a);
#define sz(a) (a).size()
int n,m;int ans;

int main()
{
    int i,j,r,c,T,w,cs=0;
    freopen("A-large.in","r",stdin);
    freopen("aout.txt","w",stdout);
    cin>>T;
    //while(scanf("%d",&n)==1)
    while(T--)
    {
        scanf("%d %d %d",&r,&c,&w);
        int hit=0;
        for(i=1;i<=r;i++)
        {
            hit+=c/w;
        }
        ans=hit+w-1;
        if(c%w)ans++;
        printf("Case #%d: %d\n",++cs,ans);
    }

    return 0;
}

