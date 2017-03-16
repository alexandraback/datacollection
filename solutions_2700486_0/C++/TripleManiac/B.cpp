#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int l,r,n,m,t,x,y,sum,cas,tst;
int ll,rr;
int cal;
int an,tot;
double f[3000][3000],ans;
int main()
{
    scanf("%d",&tst);
    for (cas=1;cas<=tst;cas++)
    {
        scanf("%d%d%d",&t,&x,&y);
        tot=0;
        sum=0;
        for (n=1;;n+=4)
        {
            tot+=n;
            if (tot>=t) break;
            sum+=2;
        }
        if (x<0) x=-x;
        printf("Case #%d: ",cas);
        if (x+y<sum)
        {
           printf("1.0\n");
           continue;
        }
        if (x+y>sum)
        {
           printf("0.0\n");
           continue;
        }
        if (t==tot)
        {
           printf("1.0\n");
           continue;
        }
        memset(f,0,sizeof(f));
        f[0][0]=1;
        m=(n-1)>>1;
        cal=t-(tot-n);
//        cout<<m<<" "<<cal<<endl;
        for (t=0;t<cal;t++)
        {
            for (l=0;l<=t;l++)
            {
                r=t-l;
                if (l>m) continue;
                if (r>m) continue;
                if (l==m)
                {
                   f[l][r+1]+=f[l][r];
                   continue;
                }
                if (r==m)
                {
                   f[l+1][r]+=f[l][r];
                   continue;
                }
                f[l+1][r]+=0.5*f[l][r];
                f[l][r+1]+=0.5*f[l][r];
            }
        }
//        cal=1;
/*        for (r=0;r<=m;r++)
        {
            l=cal-r;
            if (l<0) continue;
            if (l>m) continue;
            cout<<r<<" "<<l<<" "<<f[r][l]<<endl;
        }*/
        y++;
        ans=0;
        for (r=y;r<=m;r++)
        {
            l=cal-r;
            if (l<0) continue;
            if (l>m) continue;
            ans+=f[l][r];
        }
        printf("%.9lf\n",ans);
    }
//    while(1);
    return 0;
}
