#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct Node
{
    int a,b,c;
};
Node x[100];
struct Node2
{
    int a[10];
    int b;
};
int T;
int A,B,C,n;
int X;
int m[100];
int aa[5][5],bb[5][5],cc[5][5];
int ANS;
int ans[100];

int rec(int h)
{
    if(h==X)
    {
        int ab=0;
        for(int i=0;i<X;i++)
        {
            if(m[i]==1)
            {
                ab++;
            }
        }
        if(ab <= ANS)return 0;
        int k,p=0;;
        for(int i=1;i<=C;i++)for(int j=1;j<=C;j++){aa[i][j]=0;bb[i][j]=0;cc[i][j]=0;}
        for(int i=0;i<X;i++)
        {
            if(m[i]==1)
            {
                aa[x[i].a][x[i].b]++;
                bb[x[i].a][x[i].c]++;
                cc[x[i].b][x[i].c]++;
                p++;
            }
        }
        k=1;
        for(int i=1;i<=C;i++)
        {
            for(int j=1;j<=C;j++)
            {
                if(aa[i][j]>n){k=0;break;}
                if(bb[i][j]>n){k=0;break;}
                if(cc[i][j]>n){k=0;break;}
            }
        }
        if(k==1)
        {
            if(p>ANS)
            {
                for(int i=0;i<X;i++)ans[i]=m[i];
                ANS = p;
            }
            //printf(">%d\n",ANS);
        }
        return 0;
    }
    m[h] = 0;
    rec(h+1);
    m[h] = 1;
    rec(h+1);
    return 0;
}
int main()
{
  freopen("C-small-attempt1 (1).in","r",stdin);
   freopen("C-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d %d %d %d",&A,&B,&C,&n);
    X = 0;
    for(i=1;i<=A;i++)
    {
        for(j=1;j<=B;j++)
        {
            for(k=1;k<=C;k++)
            {
                x[X].a = i;
                x[X].b = j;
                x[X].c = k;
                X++;
            }
        }
    }
    ANS = 0;
    rec(0);
    printf("Case #%d: %d\n",ii,ANS);
    for(i=0;i<X;i++)
    {
        if(ans[i]==1)printf("%d %d %d\n",x[i].a,x[i].b,x[i].c);
    }
}

    return 0;
}
