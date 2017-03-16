#include<stdio.h>
struct element{int l,c;};
int vl[9]={0,-1,-1,-1,0,0,1,1,1};
int vc[9]={0,-1,0,1,-1,1,-1,0,1};
int l, j, c, i, n, m, nrp, nrat, inc, sf, d, ln, cn, x, k, ne, t, ii, iii, jjj;
int viz[55][55], a[55][55], nr[55][55], at[55][55], sol[55*55];
element co[55*55], el;
bool ok;

void afisare()
{
    a[i][j]=2;
    for (iii=1;iii<=n;iii++)
    {
        for (jjj=1;jjj<=m;jjj++)
        {
            if (a[iii][jjj]==-1)
                printf("*");
            if (a[iii][jjj]==0)
                printf(".");
            if (a[iii][jjj]==2)
                printf("c");
        }
        printf("\n");
    }
}

void parcurgere()
{
    l=i;    c=j;
    if (nr[l][c]==0)
    {
        co[1].l=l;  co[1].c=c;  inc=sf=1;
        viz[l][c]=nrp;
        while (inc<=sf)
        {
            el=co[inc]; inc++;
            for (d=1;d<=8;d++)
            {
                ln=el.l+vl[d]; cn=el.c+vc[d];
                if ((ln>=1)&&(ln<=n)&&(cn>=1)&&(cn<=m))
                {
                    if ((viz[ln][cn]<nrp)&&(a[ln][cn]==0))
                    {
                        if (nr[ln][cn]==0)
                        {   co[++sf].l=ln;  co[sf].c=cn;    }
                        nrat++;
                        viz[ln][cn]=nrp;
                    }
                }
            }
        }
    }
}

void verificare()
{
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            a[i][j]=viz[i][j]=nr[i][j]=at[i][j]=0;
    for (i=1;i<=k;i++)
    {
        x=sol[i];
        l=1+(x-1)/m;
        c=x-(l-1)*m;
        a[l][c]=-1;
        for (d=1;d<=8;d++)
            nr[l+vl[d]][c+vc[d]]++;
    }
    nrp=0;
    for (i=1;((i<=n)&&(!ok));i++)
        for (j=1;((j<=m)&&(!ok));j++)
            if (a[i][j]==0)
            {
                nrp++;  nrat=0;
                parcurgere();
                if (nrat+k+1==ne)
                {
                    ok=1;
                    afisare();
                }
            }
}

void gen(int poz)
{
    if (poz==k+1)
        verificare();
    else
    {
        if (!ok)
            for (int x=sol[poz-1]+1;ne-x>=k-poz;x++)
            {
                sol[poz]=x;
                gen(poz+1);
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
        scanf("%ld %ld %ld",&n,&m,&k);
        printf("Case #%ld:\n",ii);
        ne=n*m; ok=0;
        gen(1);
        if (!ok)
            printf("Impossible\n");
    }
    return 0;
}

