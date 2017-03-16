#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("b.txt","w",stdout);
    int t,cas,i,n,m,p,ans,x,y;
    cin>>t;
    //cout<<t<<endl;
    for (cas=1; cas<=t; cas++)
    {
        scanf("%d%d%d",&n,&m,&p);
        ans=0;
        for (i=1; i<=n; i++)
        {
            scanf("%d",&x);
            if (x%3==1)
            {
                x=x/3;
                if (x+1>=p) ans++;
            }
            else if (x%3==2)
            {
                x=x/3+1;
                if (x>=p) ans++;
                else if (x+1>=p && x+1<=10 && m>0)
                {ans++; m--;}
            }
            else
            {
                x=x/3;
                if (x>=p) ans++;
                else if (x-1>=0 && x+1>=p && m>0)
                {ans++; m--;}
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
