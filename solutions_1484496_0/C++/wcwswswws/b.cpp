#include<stdio.h>
#include<string.h>

int a[(1<<20)],b[20*100000][2],c[20];
int n,t,tt;

void work(int o,int p,int q)
{
    if (o>n)
    {
        if (b[q][0]==0) {b[q][0]=p;} else {b[q][1]=p;}
        return;
    }
    work(o+1,p,q);
    work(o+1,p+(1<<(o-1)),q+c[o-1]);
}

void work1(int o)
{
    int j=1;
    while (o!=0)
    {
        int oo=1;
        if ((o&1)==1) {printf("%d",c[j-1]);oo=0;}
        o/=2;
        j++;
        if ((o!=0)&&(oo==0)) printf(" ");
    }
    printf("\n");
}

int main()
{
    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("2.txt","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        printf("Case #%d:\n",t);
        scanf("%d",&n);
        for (int i=0;i<20;i++) scanf("%d",&c[i]);
        memset(b,0,sizeof(b));
        work(1,0,0);
        bool check=false;
        for (int i=0;i<=2000000;i++)
        if ((b[i][0]>0)&&(b[i][1]>0))
        {
            work1(b[i][0]);
            work1(b[i][1]);
            check=true;
            break;
        }
        if (!check) printf("Impossible\n");
    }
    return 0;
}
