#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>

using namespace std;
const int N=2000005;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.txt","w",stdout);
    int t,cas,l,r,s,p,ans,x,i,j;
    cin>>t;
    for (cas=1; cas<=t; cas++)
    {
        scanf("%d%d",&l,&r);
        s=10; p=1;
        while (l>=s) {s*=10; p++;} s/=10;
        ans=0;
        for (i=l; i<r; i++)
        {
            x=i;
            map<int,bool> m;
            for (j=1; j<p; j++)
            {
                x=(x%s)*10+(x/s);
                if (x>i && x<=r && m[x]==0)
                {m[x]=1; ans++;}
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
