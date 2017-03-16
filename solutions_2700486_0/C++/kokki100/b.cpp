#include<stdio.h>
using namespace std;
int a,b,c,d,e,f,g;
int bole;
double ans;
int dp[1000][1000];
int zz[10];
void cari(int x, int y, double z,int v)
{
    //if (b==6) printf("%d %d %d %d %lf\n",x,y,v,d,z);
    if (c<0)
    {
        if (x==d+1) {ans+=z;
        return;}
    }
    else
    {
        if (y==d+1){ ans+=z;
        return;}
    }
    if (v>0)
    {
        if (x<f)
        {
            cari(x+1,y,z/2,v-1);
            cari(x,y+1,z/2,v-1);
        }
        else
            cari(x,y+1,z/2,v-1);

    }
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    zz[1]=1;
    g=2;
    for (b=2;b<=9;b++)
    {
        zz[b]=zz[b-1];
        zz[b]+=g;
        g++;
        zz[b]+=g;
    }
    scanf("%d",&a);
    for (b=1;b<=a;b++)
    {
        ans=0;
        bole=0;
        scanf("%d %d %d",&e,&c,&d);
        if (c%2==0)
        {
            if (d%2!=0)
            {
                printf("Case #%d: %lf\n",b,ans);
                bole=1;
            }
        }
        else
            if (d%2==0)
            {
                printf("Case #%d: %lf\n",b,ans);
                bole=1;
            }
        if (c>40 || d>40 ) {printf("Case #%d: %lf\n",b,ans);bole=1;}
        if (bole==0)
        {
            if (c==0)
            {
                d/=2;
                d++;
                if (e>=zz[d]) ans=1;
                else ans=0;
            }
            else
            {
                f=(c+d)/2+1;
                if (e>=zz[f]) ans=1;
                else
                {
                    cari(0,0,1,e-zz[f-1]);
                }
            }
            printf("Case #%d: %lf\n",b,ans);
        }
    }
    return 0;
}
