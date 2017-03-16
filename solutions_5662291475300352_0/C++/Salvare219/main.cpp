#include<bits/stdc++.h>
using namespace std;


pair<int,int>p[30];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,k=0;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int d,h,m;
            scanf("%d%d%d",&d,&h,&m);
            for(int j=0;j<h;j++)
                p[k++]=make_pair(d,m+j);
        }
        int ans;
        sort(p,p+k);
        if(k==1)ans=0;
        else if(k==2)
        {
            if(p[0].second==p[1].second)ans=0;
            else if(p[0].second<p[1].second)
            {
                double v1=360.0/p[0].second,v2=360.0/p[1].second;
                double ct=(p[1].first-p[0].first)/(v1-v2);
                double pos=p[0].first+ct/p[0].second*360.0;
                if(pos>360.0)ans=0;
                else
                {
                    double dt=360.0/(v1-v2);
                    if(pos+dt/p[1].second*360.0>360.0)ans=0;
                    else ans=1;
                }
            }
            else
            {
                double v1=360.0/p[0].second,v2=360.0/p[1].second;
                double dt=(360.0-(p[1].first-p[0].first))/(v2-v1);
                if(p[0].first+dt/p[0].second*360.0>360.0)ans=0;
                else ans=1;
            }
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
