#include <stdio.h>
using namespace std;
int t,a[300],n,m,x,mc,pus[400],contor;
bool exista;
//====================================================
typedef struct
{
    int cod,minte;
    int b[300];
} numere;
numere c[400];
//====================================================
void caut(int x)
{
    for(int i=1; i<=m; ++i)
    {
        if(c[i].cod==x)
        {
            contor++;
            pus[contor]=c[i].minte;
            for(int j=1; j<=c[i].b[0]; ++j)
            {
                if(c[i].b[j]>mc)mc=c[i].b[j];
                a[ c[i].b[j] ]++;
            }
            c[i].cod=-1;
        }
    }
}
//====================================================
int main()
{
    freopen("sergiu.in","r",stdin);
    freopen("sergiu.out","w",stdout);
    scanf("%d",&t);
    for(int k=1; k<=t; ++k)
    {
        contor=0;
        printf("Case #%d: ",k);
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            a[x]++;
            if(x>mc)mc=x;
        }
        for(int k1=1; k1<=m; ++k1)
        {
            scanf("%d %d",&c[k1].cod,&x);
            c[k1].minte=k1;
            for(int i=1; i<=x; ++i)
                scanf("%d",&c[k1].b[i]);
            c[k1].b[0]=x;
        }
        do
        {
            exista=false;
            for(int i=1; i<=mc; ++i)
            {
                if(a[i]!=0)
                {
                    exista=true;
                    a[i]--;
                    caut(i);
                }
            }
        }
        while(exista);
        if(contor==m)
        {
            for(int i=1;i<=contor;++i)printf("%d ",pus[i]);
        }
        else
        {
            printf("IMPOSSIBLE");
        }
        for(int i=1;i<=mc;++i)a[i]=0;
        for(int i=1;i<=contor;++i)pus[i]=0;
        printf("\n");
    }
    return 0;
}
