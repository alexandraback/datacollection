#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define maxn 9


int main()
{
    int t,ks[2<<3][2<<3],a,b,i,j,cas=0,k;
    double p[maxn],p1[maxn],ans,temp;

    freopen("A-small-attempt0.in","r",stdin);
	freopen("out.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        for(i=0;i<a;i++) cin>>p[i];
        if (a==1)
        {
           ans=b-a-p[0]*(b+1);
           if (ans>0) ans=b+2;
           else ans+=b+2;
           printf("Case #%d: %.6lf\n",++cas,ans);
        }
        else
        if (a==2)
        {
            for(i=0;i<4;i++)
            {
                p1[i]=1;
                k=i;
                for(j=0;j<=1;j++)
                {
                    p1[i]=p1[i]*(k&1?1-p[1-j]:p[1-j]);
                    k=k>>1;
                }
            }
            ks[0][0]=b-a+1;
            ks[0][1]=ks[0][2]=ks[0][3]=2*b-a+2;
            ks[1][0]=ks[1][1]=b-a+3;
            ks[1][2]=ks[1][3]=2*b-a+4;
            ks[2][0]=ks[2][1]=ks[2][2]=ks[2][3]=b+3;
            ks[3][0]=ks[3][1]=ks[3][2]=ks[3][3]=b+2;
            ans=b*4;
            for(i=0;i<4;i++)
            {
                temp=0;
                for(j=0;j<4;j++)
                    temp+=p1[j]*ks[i][j];
                if (temp<ans) ans=temp;
            }
            printf("Case #%d: %.6lf\n",++cas,ans);
        }
        else
        {
            for(i=0;i<8;i++)
            {
                p1[i]=1;
                k=i;
                for(j=0;j<=2;j++)
                {
                    p1[i]=p1[i]*(k&1?1-p[2-j]:p[2-j]);
                    k=k>>1;
                }
            }
            ks[0][0]=b-a+1;
            for(i=1;i<8;i++)
                ks[0][i]=2*b-a+2;
            ks[1][0]=ks[1][1]=b-a+3;
            for(i=2;i<8;i++)
                ks[1][i]=2*b-a+4;
            ks[2][0]=ks[2][1]=ks[2][2]=ks[2][3]=b-a+5;
            for(i=4;i<8;i++)
                ks[2][i]=2*b-a+6;
            for(i=0;i<8;i++)
                ks[3][i]=b+4;
            for(i=0;i<8;i++)
                ks[4][i]=b+2;
            ans=b*8;
            for(i=0;i<5;i++)
            {
                temp=0;
                for(j=0;j<8;j++)
                    temp+=p1[j]*ks[i][j];
                if (temp<ans) ans=temp;
            }
            printf("Case #%d: %.6lf\n",++cas,ans);
        }
    }
    return 0;
}
