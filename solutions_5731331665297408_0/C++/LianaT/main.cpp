#include<stdio.h>
#include<algorithm>
using namespace std;
#define nmax 9
struct element{int nr, poz;};
int t, ii, n, m, i, a, b, sf, st[nmax], padev[nmax], fol[nmax], ex[nmax][nmax], sol[nmax], j;
element v[nmax];
bool ok;

bool cmp(element a, element b)
{    return (a.nr<b.nr);    }

void citire()
{
    scanf("%ld %ld",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%ld",&v[i].nr);
        v[i].poz=i;
    }
    sort(v+1,v+1+n,cmp);
    for(i=1;i<=n;i++)
        padev[v[i].poz]=i;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            ex[i][j]=fol[i]=0;
    for (i=1;i<=m;i++)
    {
        scanf("%ld %ld",&a,&b);
        a=padev[a]; b=padev[b];
        ex[a][b]=ex[b][a]=1;
    }
}

void verificare()
{
    sf=ok=1;   st[1]=sol[1];
    for (i=2;((i<=n)&&(ok));i++)
    {
        while ((ex[st[sf]][sol[i]]==0) && (sf>=1))
            sf--;
        ok=ok&&(sf>0);
        st[++sf]=sol[i];
    }
}

void gen(int poz)
{
    if ((poz==n+1)&&(!ok))
        verificare();
    else
    {
        if (!ok)
            for (int x=1;((x<=n)&&(!ok));x++)
                if (!fol[x])
                {
                    fol[x]=1;   sol[poz]=x;
                    gen(poz+1);
                    fol[x]=0;
                }
    }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        citire();
        ok=0;
        gen(1);
        printf("Case #%ld: ",ii);
        for (i=1;i<=n;i++)
            printf("%ld",v[sol[i]].nr);
        printf("\n");
    }
    return 0;
}
