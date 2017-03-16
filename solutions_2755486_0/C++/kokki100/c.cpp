#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int a,b,c,d,e,f,da,x,l,r,s,de,mo,exp;
vector<pair<pair<int,int>,pair<int,int> > > v;
pair<pair<int,int>,pair<int,int> > p;
int zz[300000];
int zz2[300000];
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&a);
    for (b=1;b<=a;b++)
    {
        v.clear();
        scanf("%d",&c);
        memset(zz,0,sizeof(zz));
        memset(zz2,0,sizeof(zz2));
        for (d=1;d<=c;d++)
        {
            scanf("%d %d %d %d %d %d %d %d",&da,&x,&l,&r,&s,&de,&mo,&exp);
            p.first.first=da;
            p.first.second=s;
            p.second.first=l+1+100000;
            p.second.second=r+100000;
            for (e=1;e<=x;e++)
            {
                v.push_back(p);
                p.first.first+=de;
                p.first.second+=exp;
                p.second.first+=mo;
                p.second.second+=mo;
            }
        }
        sort(v.begin(),v.end());
        e=v[0].first.first;
        int ans=0;
        int bole;
        for (d=0;d<v.size();d++)
        {
            bole=0;
            if (v[d].first.first!=e)
            {
                for (f=0;f<290000;f++)
                    zz[f]=max(zz[f],zz2[f]);
                memset(zz2,0,sizeof(zz2));
                e=v[d].first.first;
            }

            //if (v[d].first.first==10) printf("%d %d %d\n",zz[2],v[d].second.first,v[d].second.second);
            for (int i=v[d].second.first;i<=v[d].second.second;i++)
            {
                if (zz[i]<v[d].first.second)
                {
                    bole=1;
                    zz2[i]=max(zz2[i],v[d].first.second);
                }
            }
            if (bole) ans++;
            //printf("%d %d\n",ans,v[d].first.first);
        }
        printf("Case #%d: %d\n",b,ans);
    }
    return 0;
}
