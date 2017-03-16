#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int C[1000];
double aa[805][805];

void makec()
{
    C[0]=1;
    for (int i=1;i<805;i++)
    {
        C[i]=C[i-1]+((i*2+1)*2-1);
    }
}
void makeaa()
{
    for (int i=0;i<805;i++)
    {
        for (int j=0;j<805;j++)
        {
            aa[i][j]=0.0;
        }
    }
    aa[0][0]=0.5;
    for (int i=1;i<805;i++)
    {
        aa[i][i]=aa[i-1][i-1]/2;
        aa[i][0]=1-aa[i][i];
        for (int j=1;j<i;j++)
        {
            aa[i][j]=(aa[i-1][j]+aa[i-1][j-1])/2;
        }
    }
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    makec();
    makeaa();
    int amm,cnt=0;
    scanf("%d",&amm);
    while (amm--)
    {
        cnt++;
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (b<0)b=-b;

        int t=lower_bound(C,C+800,a)-C;

        if (t==0)
        {
            if (b+c==0)printf("Case #%d: 1.0\n",cnt);
            else printf("Case #%d: 0.0\n",cnt);
            continue;
        }

        int left=a-C[t-1];
        //printf("%d\n",left);

        if ((b+c)/2<t)printf("Case #%d: 1.0\n",cnt);
        else if ((b+c)/2>t)printf("Case #%d: 0.0\n",cnt);
        else
        {
            int A=(left>t*2)?(t*4-left):left;
            int N=(left>t*2)?c-(t*2-A):c;
            if (N<0)printf("Case #%d: 1.0\n",cnt);
            else
            {
                if (N>A-1)printf("Case #%d: 0.0\n",cnt);
                else printf("Case #%d: %.7f\n",cnt,aa[A-1][N]);
            }
        }
    }
    return 0;
}
