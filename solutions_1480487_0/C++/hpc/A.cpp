#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <string>
#define MAXN 20
using namespace std;
int tmp=0;
struct POINT
{
    double s,p;
    int id;
    bool operator<(const POINT& t)const
    {
        if(tmp==0) return s<t.s;
        else if(tmp==1) return id<t.id;
    }
}s[MAXN];
double sum,S;
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,ca,i,j,n;
    scanf("%d",&t);
    for(ca=1;ca<=t;++ca)
    {
        scanf("%d",&n);
        sum=0;
        for(i=0;i<n;++i)
        {
            scanf("%lf",&s[i].s);
            sum+=s[i].s;
            s[i].p=s[i].s;
            s[i].id=i;
        }
        S=sum;

        tmp=0;
        sort(s,s+n);
        i=1;
        while(sum>0)
        {
            //
            //cout<<s[0].s<<" "<<s[1].s<<" ";
            if(i>=n)
            {
                sum/=n;
                for(j=0;j<n;++j)
                {
                    s[j].s+=sum;
                }
                break;
            }
            else if( (s[i].s-s[i-1].s)*i <sum )
            {
                for(j=0;j<i;++j)
                {
                    sum-=(s[i].s-s[i-1].s);
                    s[j].s=s[i].s;

                }//cout<<sum<<" ";
                //sum-=((s[i].s-s[i-1].s)*i);
            }
            else
            {
                sum/=i;
                for(j=0;j<i;++j)
                {
                    s[j].s+=sum;
                }
                break;
            }
            i++;
        }
        printf("Case #%d:",ca);
        tmp=1;
        sort(s,s+n);
        for(i=0;i<n;++i)
        {
            printf(" %.6lf",100*(s[i].s-s[i].p)/S);
        }
        putchar('\n');
    }
    return 0;
}
