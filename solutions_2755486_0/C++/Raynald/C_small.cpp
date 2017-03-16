#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int T;
int wall[2010];
int now;
int a,b,c,d,e,f,g,h;
int aa[200][10];
int tmp;
int n;
int ans;
bool ff[200];
int k1,k2;

int main()
{
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        scanf("%d",&n);
        memset(wall,0,sizeof(wall));
        ans=0;now=0;
        memset(aa,0,sizeof(aa));
        for(int j=1;j<=n;j++)
        {
            scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
            //scanf("%d %d %d %d %d %d %d %d",d[j],n[j],w[j],e[j],s[j],d_d[j],d_p[j],d_s[j]);
            //
            for(int k=0;k<b;k++)
            {
                now++;
                aa[now][1]=a+f*k;
                aa[now][2]=c+g*k;
                aa[now][3]=d+g*k;
                aa[now][4]=e+h*k;
            }
        }
            for(int k=1;k<now;k++)
                for(int l=k+1;l<=now;l++)
                {
                    if(aa[k][1]>aa[l][1])
                    {
                        tmp=aa[k][1];aa[k][1]=aa[l][1];aa[l][1]=tmp;
                        tmp=aa[k][2];aa[k][2]=aa[l][2];aa[l][2]=tmp;
                        tmp=aa[k][3];aa[k][3]=aa[l][3];aa[l][3]=tmp;
                        tmp=aa[k][4];aa[k][4]=aa[l][4];aa[l][4]=tmp;
                    }
                }
            k1=1;
            while(k1<=now)
            {
            //    printf("%d %d %d %d \n",aa[k][1],aa[k][2],aa[k][3],aa[k][4]);
                k2=k1+1;
                while(aa[k2][1]==aa[k1][1] && k2<=now)k2++;
                memset(ff,0,sizeof(ff));
                for(int k=k1;k<k2;k++)
                {
                    for(int l=aa[k][2];l<aa[k][3];l++)
                        if(wall[l+300]<aa[k][4]) {ff[k-k1]=1;ans++;break;}
                }
                for(int k=k1;k<k2;k++)
                {
                    if(ff[k-k1])
                    for(int l=aa[k][2];l<aa[k][3];l++)
                        if(wall[l+300]<aa[k][4]) wall[l+300]=aa[k][4];
                }
                k1=k2;
            }    
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
